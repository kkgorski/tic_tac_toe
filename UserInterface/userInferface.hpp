#include <iostream>

class UserInterface
{
  public:
    char getUserCharacter()
    {
      std::string userInput= "";
      std::cout << "Please choose you character to be 'x' or 'o'" << std::endl;
      do
      {
	std::cin >> userInput;
	std::cout << std::endl;
      }while(userInput != "x" && userInput != "o");

      return userInput.c_str()[0];
    }

    Point getUserPoint(unsigned int bound)
    {
      Point userPoint;
      do
      {
	std::cout << "Give me coordinate x" << std::endl;
	std::cin >> userPoint.x;
	std::cout << "Give me coordinate y" << std::endl;
	std::cin >> userPoint.y;
      }while(!userPoint.isValid(bound));

      return userPoint;
    }

    void drawScreen(const charVectorVector& rawBoard)
    {
      for(auto const& row: rawBoard)
      {
	drawRow(row);
	if(&row != &rawBoard.back())
	{
	  std::cout << "-+-+-\n";
	}
      }
    }

    void drawRow(const charVector& row)
    {
      for(auto const& character: row)
      {
	std::cout << character;
	if(&character != &row.back())
	{
	  std::cout << "|";
	}
      }
      std::cout << std::endl;
    }
};

