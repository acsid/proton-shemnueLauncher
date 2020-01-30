#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>


using namespace std;

void menu();
void mainMenu();
void options(int episode);
int choice1 = 0;

int main(int argc, char** argv) {



    menu();



    return 0;
}


void menu(){

        do {
        mainMenu();

        switch(choice1) {

            case 1:
                options(1);
                break;

            case 2:
              	options(2);
                break;

            case 3:
                break;

        }

    } while(choice1 != 3);


}

void options(int episode) {

	const char *name, *dir;
	STARTUPINFO startup;
	PROCESS_INFORMATION process;

	/* Any parameter means load Shenmue 2 */
	if (episode == 2)
	{
		name = "sm2/Shenmue2.exe";
		dir = "sm2";
	}
	else
	{
		name = "sm1/Shenmue.exe";
		dir = "sm1";
	}

	ZeroMemory(&startup, sizeof(startup));
	ZeroMemory(&process, sizeof(process));
	startup.cb = sizeof(startup);
	if (CreateProcess(
		name,
		NULL,
		NULL,
		NULL,
		TRUE,
		0,
		NULL,
		dir,
		&startup,
		&process
	)) {
		WaitForSingleObject(process.hProcess, INFINITE);
		CloseHandle(process.hProcess);
		CloseHandle(process.hThread);
	}

}

void mainMenu(void) {

	int choice = 0;
while(choice!='3')
  {
    printf("\n\tShemnue Proton Launcher");
    printf("\n\t------------------------------");
    printf("\n\n\t 1. Shemnue 1");
    printf("\n\t 2. Shemnue 2");
    printf("\n\t 3. Exit");
    printf("\n\n Enter Your Choice: ");
    choice = getch();
    switch(choice)
    {
    case '1':
      printf("\n\nLaunching shemnue 1\n");
   	options(1);
      break;
    case '2':
      printf("\n\nLaunching shemnue 2\n");
	options(2);
	break;
    case '3':
      printf("\n\nExiting...\n");
      break;
    default:
      printf("\n\nINVALID SELECTION...Please try again\n");
    }
    (void)getch();
  }

}


