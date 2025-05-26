/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:11:30 by annabrag          #+#    #+#             */
/*   Updated: 2025/05/26 21:52:26 by annabrag         ###   ########.fr       */
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
	std::cout << BOLD HOT_PINK "[" << this->_name << "]" RESET HOT_PINK " created"
			  << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& toCopy) : AForm(toCopy)
{
	std::cout << BOLD PINK "[" << this->_name << "]" RESET PINK " copy created"
			  << RESET << std::endl;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& toCopy)
{
	if (this != &toCopy)
		AForm::operator=(toCopy);
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << BOLD PO "[" << this->_name << "]" RESET PO " destroyed" RESET << std::endl;
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
	----------------------------- [ Getters ] ----------------------------
*/
const std::string&	ShrubberyCreationForm::getName() const
{
	return (this->_name);
}

const bool&		ShrubberyCreationForm::getSignatureState() const
{
	return (this->_isSigned);
}

const uint32_t&		ShrubberyCreationForm::getRequiredGradeToSign() const
{
	return (this->_gradeToSign);
}

const uint32_t&		ShrubberyCreationForm::getRequiredGradeToExec() const
{
	return (this->_gradeToExec);
}

/*
	------------------------- [ Main function ] --------------------------
*/
void	ShrubberyCreationForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw AForm::GradeTooLowException();
	this->_isSigned = true;
}

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
    outfile << trees[idx] << std::endl;
	outfile.close();
}

void	ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	if (this->_isSigned == false)
		throw AForm::GradeTooLowException();
	if (executor.getGrade() > this->_gradeToExec)
		throw AForm::CannotExecuteException();
	createAsciiTree(this->_target);
}
