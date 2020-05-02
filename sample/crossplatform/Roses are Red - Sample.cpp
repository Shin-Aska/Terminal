#include "../../headers/Terminal"
#include <cstdlib>

int main (void)
{
	cnTerm_Activate;

	cnPrint(RED, "Roses Are Redsss\n");
	cnStartPoint(1);
	cnPrint(BLUE, "Violets Are Blue\n");
	cnPrint(CYAN, "Sugar is sweet\n");
	cnPrint(PURPLE, "And so are you. <3");
    getch();
	cnTerm_Deactivate;
}
