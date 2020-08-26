g++ hiho_w270_p1_ans.cpp -O3 -o ans.out -std=c++11
g++ hiho_w270_p1.cpp -O3 -o res.out -std=c++11

for i in `seq 1 10000`
do
    g++ gen.cpp -O3 -o gen.out -std=c++11 && ./gen.out
    ans=$(./ans.out < in.txt)
    res=$(./res.out < in.txt)
    if [ $ans==$res ];then
        echo $i $ans $res
        continue
    else
        echo "not equal, stop"
        break
    fi
done