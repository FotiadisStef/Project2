#!/bin/bash

folder="./samples"

link="http://cgi.di.uoa.gr/~ip/hwfiles/wavproc/"

files=("good" "bad_data" "bad_fmt" "bad_riff")
fileType=".wav"

for i in "${files[@]}"
do
   wget -O $folder/$i$fileType $link$i$fileType
done