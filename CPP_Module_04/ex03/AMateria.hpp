/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kal-haj- <kal-haj-@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 16:26:00 by kal-haj-          #+#    #+#             */
/*   Updated: 2026/11/17 16:26:00 by kal-haj-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>

class ICharacter;

class AMateria
{
protected:
    std::string type;

public:
    AMateria();
    AMateria(std::string const &type);
    AMateria(const AMateria &other);
    AMateria &operator=(const AMateria &other);
    virtual ~AMateria();

    std::string const &getType() const; // Returns the materia type

    virtual AMateria *clone() const = 0;
    virtual void use(ICharacter &target);
};

#endif
