#include "../headers/Terminal"
#include <cstdlib>

int main (void)
{
	cnTerm_Activate;

	cnPrint(RED, "Roses Are Red\n");
	cnStartPoint(1);
	cnPrint(BLUE, "Violets Are Blue\n");
	cnPrint(CYAN, "Sugar is sweet\n");
	cnPrint(PURPLE, "And so are you.");
    getch();
	cnTerm_Deactivate;
}
