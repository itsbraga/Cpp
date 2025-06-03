/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:11:30 by annabrag          #+#    #+#             */
/*   Updated: 2025/06/03 18:23:12 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

/*
	---------------------- [ Object Manipulation ] -----------------------
*/
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
		: AForm("Shrubbery Creation form", 145, 137), _target(target)
{
	std::cout << BOLD HOT_PINK "[" << this->getName() << "]" RESET HOT_PINK " created"
			  << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& toCopy) : AForm(toCopy)
{
	std::cout << BOLD PINK "[" << this->getName() << "]" RESET PINK " copy created"
			  << RESET << std::endl;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& toCopy)
{
	if (this != &toCopy)
	{
		AForm::operator=(toCopy);
		this->_target = toCopy._target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << BOLD PO "[" << this->getName() << "]" RESET PO " destroyed" RESET << std::endl;
}

/*
	----------------------------- [ Stream ] -----------------------------
*/
std::ostream&	operator<<(std::ostream& os, const ShrubberyCreationForm& form)
{
	if (form.getSignatureState() == false)
		os << form.getName() << " is " PO "not signed yet" RESET ".\n";
	else
		os << form.getName() << " is " PG "signed" RESET ".\n";
	os << "To execute it, Bureaucrat must have at most grade "
	   << form.getRequiredGradeToExec() << ".\n" << "To sign it, Bureaucrat "
	   << "must have at most grade " << form.getRequiredGradeToSign() << ".\n";
	return (os);
}

/*
	------------------------- [ Main functions ] -------------------------
*/
void	ShrubberyCreationForm::createAsciiTree(const std::string& target) const
{
	static const char*	trees[] = {TREE1, TREE2, TREE3, TREE4};
    const int			treeCount = sizeof(trees) / sizeof(trees[0]);
	std::ofstream		outfile;
	int					idx;

	outfile.open((target + "_shrubbery").c_str());
	if (!outfile)
	{
		std::cerr << BOLD RED "Error: " RESET << "Cannot create output file '"
				  << target << "_shrubbery'\n";
		exit(FAILURE);
	}
	idx = std::rand() % treeCount;
    outfile << PG << trees[idx] << RESET << std::endl;
	outfile.close();
}

void	ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	if (this->getSignatureState() == false)
		throw AForm::NotSignedException();
	if (executor.getGrade() > this->getRequiredGradeToExec())
		throw AForm::CannotExecuteException();
	createAsciiTree(this->_target);
}
