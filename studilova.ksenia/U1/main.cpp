#include <iostream>
#include <fstream>
#include <string>

#include "args.hpp"
#include "parser.hpp"
#include "person.hpp"

int main(int argc, char *argv[])
{
  const studilova::Args args = studilova::parseArgs(argc, argv);

  if (!args.valid_)
  {
    return 1;
  }

  std::ifstream inputFile;
  std::istream *input = &std::cin;

  if (args.hasInput_)
  {
    inputFile.open(args.inputFile_);

    if (!inputFile)
    {
      return 2;
    }

    input = &inputFile;
  }

  std::ofstream outputFile;
  std::ostream *output = &std::cout;

  if (args.hasOutput_)
  {
    outputFile.open(args.outputFile_);

    if (!outputFile)
    {
      return 2;
    }

    output = &outputFile;
  }

  studilova::PersonArray persons;
  studilova::initPersonArray(persons);

  std::size_t count = 0;
  std::size_t ignore = 0;

  std::string line;

  while (std::getline(*input, line))
  {
    studilova::Person person;

    if (studilova::parsePersonLine(line, person) && !studilova::containsPersonId(persons, person.id_))
    {
      studilova::appendPerson(persons, person);
      ++count;
    }
    else
    {
      ++ignore;
    }
  }

  for (std::size_t i = 0; i < persons.size_; ++i)
  {
    *output << persons.data_[i].id_ << ' ' << persons.data_[i].info_ << '\n';
  }

  std::cerr << count << '\n';
  std::cerr << ignore << '\n';

  studilova::destroyPersonArray(persons);

  return 0;
}
