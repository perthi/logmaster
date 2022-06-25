#!/bin/bash



dirs=$@

basedir=${PWD}

if [ -z "QT_BIN" ]; then
    MOC=$QT_BIN/moc
else
    MOC=moc
fi

   


generate_moc ()
{
    hdr=$1;
    moc_hdr=$2
    moc_cpp=$3
    # ${QT_BIN}/moc --no-warnings $hdr >  ${moc_hdr}
    $MOC --no-warnings $hdr >  ${moc_hdr}
    echo "#include " "\"""${moc_hdr}""\"" > ${moc_cpp}
}


cleanup()
{
 #  echo "!!!!!!! cleaning up"    $1/$2
 #  rm -f $1/$2
   rm -f $1/tmp.cpp
   rm -f $1/tmp.h  
}

for dir in ${dirs};do
    cd  ${basedir}/${dir}    
    #cd ..
    #cd ..
    
    echo curdir = ${PWD}
    sources=`ls *.cpp | grep -v moc`
    headers=`ls *.h | grep -v moc | grep -v resource`
    
    for hdr in ${headers}; do
        if  grep -q  Q_OBJECT $hdr  ; then
            echo ${hdr} contains MOC!!!!! > /dev/null
            tmp=${hdr%.*}
            moc_hdr=${tmp}_moc.h
            moc_cpp=${tmp}_moc.cpp 
        
            if [ -f "$moc_hdr" ]; then
                echo "$moc_hdr exist !!"
                t_moc=tmp_moc.h 
                # ${QT_BIN}/moc --no-warnings $hdr >  ${t_moc}
                $MOC --no-warnings $hdr >  ${t_moc}
                chk1=`cksum $moc_hdr | awk -F" " '{print $1}'`
                chk2=`cksum $t_moc | awk -F" " '{print $1}'`
                if [ $chk1 -eq $chk2 ]
                then
                    echo "File is identical !!!!!, doing nothing" > /dev/null
                else
                    echo "File is not identical !!!!!!"
                    mv $t_moc $moc_hdr
                fi
                
            else
                #echo "$moc_hdr DOES NOT exist !!" 
                generate_moc $hdr $moc_hdr $moc_cpp
            fi
            
            cleanup  ${basedir}/${dir}  ${t_moc} 
            
        else
            echo ${hdr} DOES NOT contains MOC!!!!! > /dev/null      
        fi

    done
done


