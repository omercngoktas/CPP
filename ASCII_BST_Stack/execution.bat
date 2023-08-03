@echo off
REM Gelen komut satırı parametresinden dosya adını alın
set "dosya_adi=%~1"

REM Dosyanın bulunduğu dizine geç
cd /d "C:\Users\omerc\Desktop\CPP\ASCII_BST_Stack"

REM mingw32-make komutunu çalıştır
mingw32-make

REM bin dizinine geç
cd bin

REM stack_bst_ascii.exe programını çalıştır ve data.txt dosyasını argüman olarak ver
.\stack_bst_ascii.exe "%dosya_adi%"

REM Önceki dizine geri dön
cd ..


@REM REM Pencereyi açık tutmak için bir tuşa basılmasını bekleyin
@REM pause
