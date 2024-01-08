/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <fedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 15:06:49 by fedmarti          #+#    #+#             */
/*   Updated: 2024/01/08 20:14:55 by fedmarti         ###   ########.fr       */
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

std::string ft_sreplace( std::string str, std::string find, std::string replace )
{
	if (find == replace)
		return (str);
	for (size_t match = str.find(find); match < str.size(); match = str.find(find))
	{
		std::string rest = str.substr(match + find.length());
		str.erase(match);
		str.append(replace);
		str.append(rest);
	}
	return (str);
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
	fcontent = ft_sreplace(fcontent, argv[2], argv[3]);

	std::string	newname = argv[1];
	newname += ".replace";
	std::ofstream newfile(newname.c_str());
	newfile << fcontent;
	newfile.close();
}
