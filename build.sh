# files & folders to build
# src/*
# Tests/* to rename --> tests/*
# makefile
# test.sh

# all that in prod folder 

PROD=prod
GROUP_NAME=H4412

if [  ! -z $1 -a $1 = "clean" ]; then
    rm -rf ${PROD}
    rm ${PROD}.tar.gz ${PROD}.zip
    echo "[*] Suppression du dossier de production"
    exit 0
fi

echo "[*] Début de la mise en prod..."
mkdir "${PROD}"
mkdir ${PROD}/object

cp -r src/ ${PROD}/src
cp -r Tests/ ${PROD}/tests
cp makefile ${PROD}/
cp test.sh ${PROD}/


cd ${PROD}

echo "[*] Fin de la mise en prod..."
head -n 2 test.sh > test.tmp
mv test.tmp test.sh
chmod +x test.sh
echo "[*] Suppression de la fin du fichier test.sh"
sed -i -e "s/Tests/tests/g" test.sh
echo "[*] Remplacement du fichier de test"

cd ..

tar -cf ${PROD}.tar ${PROD}
gzip ${PROD}.tar
echo "[*] regroupement et compression du dossier en .tar.gz"

zip -r ${PROD} ${PROD}
mv ${PROD}.zip ${GROUP_NAME}.zip
echo "[*] regroupement et compression du dossier en .zip"
