#!/bin/bash
(cd Tests && ./mktest.sh)

exit 0

echo "-----------------------------------------------------------"
echo "Tests pour le binome : H4412"
echo "-----------------------------------------------------------"

nTestCount=0
nSuccesfulTests=0

# structure d'un test
# test/
#   test.lt (lutin code to test)
#   test.in (command line)
#   test.out (expected content)

for test in tests/*
do
    # "Recherche pour ${test}"
    if [ -d ${test} ]; then
        input_file=`find ${test}/ -name '*.in'`
        lutin_file=`find ${test}/ -name '*.lt'`
        output_file=`find ${test}/ -name '*.out'`

        if [ -f ${input_file} -a -f ${lutin_file} -a -f ${output_file} ]; then
            # faire les comparaisons
            echo -e "\t\t# Lancement de ${test}"
            let "nTestCount=$nTestCount+1"
            `cat ${input_file}` 2> /dev/null | grep '^#' > ${test}/test.tmp 2> /dev/null

            if [ $? -ne 0 ]; then
                echo -e "\n\n\t\t/!\ L'executable n'est pas disponible. Veuillez taper \`make\` avant de lancer les tests.\n\n"
                exit 1
            fi

            #cat ${input_file}
            diff -wB ${output_file} ${test}/test.tmp > ${test}/test2.tmp
            if [ $? -eq 0 ]; then
                echo -e "${test} est passé !"
                let "nSuccesfulTests=$nSuccesfulTests+1"
            else
                echo -e "${test} n'est pas passé !"
                echo -e "Résultat obtenu :"
                cat ${test}/test2.tmp
            fi

            echo ""

            if [ -f ${test}/test.tmp -a -f ${test}/test2.tmp ]; then
                rm ${test}/test.tmp ${test}/test2.tmp
            fi
        else
            echo "# Fichiers pour le test ${test} introuvable !"
        fi
        #echo "# ${test} n'est pas un repertoire !"
    fi
done
echo "-----------------------------------------------------------"
echo "Tests passés avec succès : ${nSuccesfulTests}/${nTestCount}"
echo "-----------------------------------------------------------"
