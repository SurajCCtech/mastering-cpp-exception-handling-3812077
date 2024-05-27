#include <iostream>
#include <stdexcept>
#include <string>

class InsufficientSpaceException : public std::runtime_error
{
public:
  InsufficientSpaceException(const std::string &msg) : std::runtime_error(msg){}
};
void checkSpace(unsigned long availableSpace)
{
  const unsigned long requiredSpace = 100;
  if (availableSpace < requiredSpace)
  {
    throw InsufficientSpaceException("Insufficient disk space");
  }
}

int main()
{
  unsigned long spaceArray[] = {100, 130, 90};
  for (unsigned long space : spaceArray)
  {
    try
    {
      checkSpace(space);
      std::cout << "Sufficient disk space " << space << "MB" << std::endl;
    }
    catch (const std::exception &e)
    {
      std::cerr << "Error: " << e.what() << " available space " << space << "MB" << std::endl;
    }
  }
  return 0;
}