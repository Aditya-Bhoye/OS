#!/bin/bash
while true; 
do 
    echo -ne "\n1.Create 2.Display 3.Insert 4.Search 5.Modify 6.Delete 7.Exit"
    echo -n "Enter your choice : "
    read ch
    case $ch in 
    1)
        echo -n "Enter the file name : "
        read fname
        if [ -e "$fname" ]; then
            echo "File already exists "
        else
            touch "$fname"
            echo "File created successfully " 
        fi
        ;;
    2)
        echo -n "Enter file name " 
        read fname
        if [ -e "$fname" ]; then 
            echo "Displaying file content "
            cat "$fname"
        else
            echo "File does not exist "
        fi
        ;;
    3)
        echo -n "Enter file name "
        read fname
        if [ -e "$fname" ]; then
            echo -n "Enter Roll number "
            read roll
            grep -w "$roll" "$fname" >/dev/null
            if [ $? -eq 0 ]; then
                echo "Roll number already exist "
            else
                echo -n "Enter Name "
                read name
                echo "$roll" "$name" >> "$fname"
                echo "Record inserted"
            fi
        else
            echo "File does not exist "
        fi
        ;;
    4)
        echo -n "Enter file name "
        read fname
        if [ -e "$fname" ]; then 
            echo -n "Enter roll number to search "
            read roll
            grep -w "$roll" "$fname" >>/dev/null
            if [ $? -eq 0 ]; then
                echo "Record found"
                grep -w "$roll" "$fname"
            else
                echo "Record not found"
            fi
        else
            echo "File does nor exist "
        fi
        ;;
    5)
        echo -n "Enter file name "
        read fname
        if [ -e "$fname" ]; then 
            echo -n "Enter roll number "
            read roll
            grep -w "$roll" "$fname" >>/dev/null
            if [ $? -eq 0 ]; then
                echo -n "Enter new roll and new name "
                read nroll nname
                grep -w "$nroll" "$fname" >>/dev/null
                if [ $? -eq 0 ]; then 
                    echo "New roll number is already exist try another one"
                else
                    grep -vw "$roll" "$fname" > temp
                    echo "$nroll" "$nname" >> temp
                    mv temp "$fname"
                    echo "Record Modify successfully"
                fi
            else
                echo "Roll number does not exist "
            fi
        else
            echo "File does not exist"
        fi
        ;;
    6)
        echo -n "Enter file name "
        read fname
        if [ -e "$fname" ]; then 
            echo -n "Enter roll number to delete "
            read roll
            grep -w "$roll" "$fname" >> /dev/null
            if [ $? -eq 0 ]; then 
                grep -vw "$roll" "$fname" >temp  
                mv temp "$fname"
                echo "Record delete successfully"
            else
                echo "Roll number does not exist"
            fi
        else
            echo "File does not exist "
        fi
        ;;
    7)
        echo "Exiting....."
        exit 0
        ;;
    *)
        echo "Invalid Choice"
        ;;
    esac
done
