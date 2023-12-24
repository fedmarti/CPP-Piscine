/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 15:06:49 by fedmarti          #+#    #+#             */
/*   Updated: 2023/12/24 17:28:00 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>


std::string read_file(char *file_name, bool &success)
{
	std::ifstream input_file(file_name);
	std::string fcontent, tempstr;

	success = !input_file.fail();
	while ( getline(input_file, tempstr) )
	{
		fcontent.append(tempstr);
		if (!input_file.eof())
			fcontent.append("\n");
	}
	input_file.close();
	return (fcontent);
}

int	main ( int argc, char **argv )
{
	if (argc != 4)
	{
		std::cout << "Wrong number of args\n<filename> <s1> <s2>\n";
		return 1;
	}
	bool		successfull_read = false;
	std::string fcontent = read_file(argv[1], successfull_read);
	if (!successfull_read)
	{
		std::cout << "Errors reading from " << argv[1] << std::endl;
		return 1;
	}
	
	std::string find = argv[2];
	// std::cout << fcontent << std::endl; // just reads file for debugging
	for (size_t match = fcontent.find(find); match < fcontent.size(); match = fcontent.find(find))
	{
		std::string rest = fcontent.substr(match + find.length());
		fcontent.erase(match);
		fcontent.append(argv[3]);
		fcontent.append(rest);
	}

	std::string	newname = argv[1];
	newname += ".replace";
	std::ofstream newfile(newname.c_str());
	newfile << fcontent;
	newfile.close();
}
