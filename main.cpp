#include <iostream>
#include <cstring>
#include <stdlib.h>
#include "World.h"
//#include <unistd.h>
#include <Windows.h>

void titleScreen() {
printf(" /$$$$$$$$                     /$$ /$$              /$$$$$$$$                              \n");
printf("| $$_____/                    |__/| $/             | $$_____/                              \n");
printf("| $$       /$$$$$$$   /$$$$$$  /$$|_//$$$$$$$      | $$    /$$$$$$   /$$$$$$  /$$$$$$/$$$$ \n");
printf("| $$$$$   | $$__  $$ /$$__  $$| $$  /$$_____/      | $$$$$|____  $$ /$$__  $$| $$_  $$_  $$\n");
printf("| $$__/   | $$  \\ $$| $$  \\ $$| $$ |  $$$$$$       | $$__/ /$$$$$$$| $$  \\__/| $$ \\ $$ \\ $$\n");
printf("| $$      | $$  | $$| $$  | $$| $$  \\____  $$      | $$   /$$__  $$| $$      | $$ | $$ | $$\n");
printf("| $$$$$$$$| $$  | $$|  $$$$$$$| $$  /$$$$$$$/      | $$  |  $$$$$$$| $$      | $$ | $$ | $$\n");
printf("|________/|__/  |__/ \\____  $$|__/ |_______/       |__/   \\_______/|__/      |__/ |__/ |__/\n");
printf("                     /$$  \\ $$                                                             \n");
printf("                    |  $$$$$$/                                                             \n");
printf("                     \\______/                                                              \n");
}

int main() {
	World W;
	system("CLS");
	titleScreen();
	Sleep(1000);
	while (true) {
		try {
			system("CLS");
			W.Draw();
			W.Input();
			W.Update();
		} catch (const char * exp) {
			if (strcmp(exp, "EXIT") == 0) {
				break;
			}
		}
	}
	return 0;
}