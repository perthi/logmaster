@echo off

dir /b  *.h > files.txt


:: del *moc.h
:: del *moc.cpp


for /F "tokens=*" %%A in (files.txt) do (
 	>nul findstr "Q_OBJECT" %%A && (
	  echo "Q_OBJECT" was found in %%A !!!!!!!!!!!!!!!!!!!!!!!! > nul
	  echo(%%A|findstr /r /c:"moc" >nul && (
	   		echo file = %%A  no moch generated	
	   		) || (
	   		..\moc --no-warnings %%A > tmp_moc.h 		
	   		fc %%~nA_moc.h tmp_moc.h > nul
	   		if  errorlevel 0 (
	   			echo generating moc files:  %%~nA_moc.h  and %%~nA_moc.cpp
	   			copy tmp_moc.h %%~nA_moc.h
	   			echo #include "%%~nA_moc.h" > %%~nA_moc.cpp
	   		) else (
	   			echo "ERROR CREATING MOC FILES !!!!"
	   		)
  	)	  
	) || (
	  echo "Q_OBJECT" was NOT found in %%A > nul
	)	
 )









 
 
del files.txt
del tmp_moc.h

exit 0