#!/usr/bin/bash
echo "The MIT License (MIT)."
echo "Copyright (c) 2022 ALIF FUSOBAR."
sleep 03
clear
sleep 01

## IP Generator list. Use many iterations as you need.

#for a in {1..100};do
#    echo "$a.1.1.1" >> ipproxy.lst
#for b in {100..200};do
#        echo "$a.$b.1.1" >> ipproxy.lst
#for c in {200..300};do
#        echo "$a.$b.$c.1" >> ipproxy.lst
#for d in {300..400};do
#        echo "$a.$b.$c.$d" >> ipproxy.lst
#           done
#       done
#    done
#done

for a in {1..254};do
    echo "10.135.$a.1" >> ipproxy.lst
    for b in {1..254};do
        echo "110.315.$a.$b" >> ipproxy.lst
    done
done

