@echo off

dir /b  *.h > files.txt

del *moc.h > nul
del *moc.cpp > nul


for /F "tokens=*" %%A in (files.txt) do (
 	>nul findstr "Q_OBJECT" %%A && (
	  echo "Q_OBJECT" was found in %%A  > nul
	  echo(%%A|findstr /r /c:"moc" >nul && (
	   		echo file = %%A  no moch generated >  nul	
	   		) || (
	   		..\moc  %%A > tmp_moc.h	   		
	   		
	   		if  errorlevel 0 (
	   			echo generating QT moc files:  %%~nA_moc.h  and %%~nA_moc.cpp
	   			copy tmp_moc.h %%~nA_moc.h > nul
	   			echo #include "%%~nA_moc.h" > %%~nA_moc.cpp
	   		) else (
	   			echo "ERROR CREATING MOC FILES !!!!"
	   		)
  	)	  
	) || (
	  echo "Q_OBJECT" was NOT found in %%A > nul
	)	
 )

del files.txt > nul
del tmp_moc.h > nul