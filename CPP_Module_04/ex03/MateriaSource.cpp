/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kal-haj- <kal-haj-@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 16:26:00 by kal-haj-          #+#    #+#             */
/*   Updated: 2026/11/17 16:26:00 by kal-haj-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
        templates[i] = 0;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
    for (int i = 0; i < 4; i++)
    {
        if (other.templates[i])
            templates[i] = other.templates[i]->clone();
        else
            templates[i] = 0;
    }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
    if (this != &other)
    {
        for (int i = 0; i < 4; i++)
        {
            delete templates[i];
            templates[i] = 0;
            if (other.templates[i])
                templates[i] = other.templates[i]->clone();
        }
    }
    return *this;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
        delete templates[i];
}

// Keeps a copy of m so it can be cloned later. m itself is deleted (we own it).
void MateriaSource::learnMateria(AMateria *m)
{
    if (!m)
        return;
    for (int i = 0; i < 4; i++)
    {
        if (!templates[i])
        {
            templates[i] = m->clone();
            delete m;
            return;
        }
    }
    delete m; // source is full
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < 4; i++)
    {
        if (templates[i] && templates[i]->getType() == type)
            return templates[i]->clone();
    }
    return 0;
}
