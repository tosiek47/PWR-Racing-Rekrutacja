- Tworzę projekt w środowisku "STM32CubeIDE" 

- Wybieram mikrokontroler "STM32F205RGT6"

- Ustawiam zegar na 16MHz 

- Wybieram watchdoga (IWDG) 

- Obliczam down-counter-reload value z równania, które znajduje się w folderze z obrazami

- Ustawiam pin PA5 jako GPIO_Output i ustawiam mu nazwę "DIODA"

- w pliku "leeed\Core\Src\main.c" w linijce 92 zmieniam sygnał (z 0 na 1 i na odwrót) dla diody podłączonej do pinu PA5, następnie nakładam delay 200ms, tak aby dioda migała z częstotliwością 5Hz. 

W pętli while(1) [linijki 101-105] ustawiam delay większy niż był wzięty w równanie (w równaniu było 20ms, a w programie jest 23ms) tak, aby watchdog resetował program, przez co dioda będzie migać. 

dodatkowo, załączam plik main.c oraz schemat mikrokontrolera, na wypadek, gdyby był problem z otwarciem pliku