rm -f tester_res.txt
rm -f over_bench_test_*
for i in {1..100}
do
ARG="`seq 1 5 | sort -R`"
./push_swap $ARG | wc -l >> tester_res.txt
BENCH=$(./push_swap $ARG | wc -l)
if [ $BENCH -ge 699 ]; then
	echo $ARG > over_bench_test_$i.txt
fi
# RES=$(./push_swap $ARG | ./checker $ARG)
# if [ $RES = 'KO' ]; then
# 	echo $ARG > failed/failed_test_$i.txt
# fi
done
python3 avg.py
ls failed