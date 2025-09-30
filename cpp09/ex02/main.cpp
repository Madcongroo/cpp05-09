/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 17:11:48 by proton            #+#    #+#             */
/*   Updated: 2025/09/30 11:37:07 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void swapElements(std::deque<int> &sequence, size_t index, size_t numInPair)
{
    if (index + numInPair > sequence.size() || numInPair % 2 != 0)
    {
        std::cerr << "Erreur: bloc invalide pour swap" << std::endl;
        return;
    }

    size_t half = numInPair / 2;

    std::deque<int>::iterator first  = sequence.begin() + index;
    std::deque<int>::iterator middle = first + half;
    std::deque<int>::iterator last   = first + numInPair;

    std::rotate(first, middle, last);
}

void    compairPairs( std::deque<int>&sequence, size_t numInPair )
{
    size_t sequenceSize = sequence.size();

    for (size_t i = 0; i < sequenceSize; i+=numInPair)
    {
        if (sequence[i + numInPair / 2 - 1] > sequence[i + numInPair - 1]) // pour savoir si le dernier nombre de chaque pair est plus petit ou plus grand que le dernier nombre de la pair suivante
            swapElements( sequence, i, numInPair );
    }
}

void    linkPairs( std::deque<int> &sequence, std::list<t_link> &link, size_t numInPairs )
{
    size_t sequenceSize = sequence.size();
    int  bNumber = 2; // the pend will never have b1, so i start with 2 (b2)

    for (size_t i = numInPairs; i < sequenceSize; )
    {
        t_link  tempLink;

        if (i + numInPairs > sequenceSize && (i + numInPairs / 2) < sequenceSize)
        {
            tempLink.bNumber = bNumber++;
            tempLink.b = sequence[i + (numInPairs / 2 - 1)];
            tempLink.a = -1;
            link.push_back(tempLink);
            break ;
        }

        tempLink.bNumber = bNumber++;
        tempLink.b = sequence[i + (numInPairs / 2 - 1)];
        tempLink.a = sequence[i + (numInPairs - 1)];
        link.push_back(tempLink);
        if (i + numInPairs > sequenceSize)
            break ;
        i += numInPairs;
    }
    for (size_t i = 0; i < sequence.size(); i++)
    {
        std::cout << sequence[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "LIST SIZE == " << link.size() << std::endl;
    for (std::list<t_link>::const_iterator it = link.begin(); it != link.end(); ++it)
    {
        std::cout << "bNumber is : " << it->bNumber << std::endl;
        std::cout << "b is : " << it->b << std::endl;
        std::cout << "a is : " << it->a << std::endl;
    }
}

void initialisePend( std::deque<int> &pend, std::deque<int> &sequence, size_t numInPair, std::list<t_link> &link )
{
    size_t sequenceSize = sequence.size();
    size_t startIndex = numInPair;

    std::cout << "NUM IN PAIR " << numInPair << std::endl;

    linkPairs(sequence, link, numInPair); // to link pairs (b, a) with indexes of the last number of (b, a)

    for (size_t i = startIndex; (i + numInPair / 2) <= sequenceSize; i++)
    {
        size_t j = 0;
        while (j < numInPair / 2)
        {
            pend.push_back(sequence[i]);
            sequence.erase(sequence.begin() + i, sequence.begin() + (i + 1));
            j++;
        }
        i += numInPair / 2 - 1;

        sequenceSize -= numInPair / 2;
    }
}

int findInLink( int pendNumber, std::list<t_link> &link )
{
    for (std::list<t_link>::iterator it = link.begin(); it != link.end(); it++)
    {
        if (pendNumber == it->b)
            return (it->a);
    }
    return (-1);
}

void    initialiseJacobstahlNumbers( std::deque<int> &jacobstahlNumbers )
{
    jacobstahlNumbers.push_back(1);
    jacobstahlNumbers.push_back(1);

    size_t i = 2;
    while (true)
    {
        size_t next = jacobstahlNumbers[i - 1] + 2 * jacobstahlNumbers[i - 2];
        if (next > 5461)
            break ;
        jacobstahlNumbers.push_back(next);
        i++;
    }
    jacobstahlNumbers.pop_front(); // removing the first 1, because we dont need it
}

// void    insertSimpleElements( std::deque<int> &sequence, std::deque<int> &pend, std::list<t_link> &link, size_t numInPairs )
// {
//     size_t  pendSize = pend.size();
//     size_t  i = pendSize;

//     while (i > 0)
//     {
//         int foundLink = findInLink(pend[i - 1], link);

//         if (foundLink != -1)
//         {
            
//         }
//     }
    
// }

void    fillNumsToInsert(std::deque<int> &numsToInsert, std::list<t_link> &link, std::deque<int> &pend, size_t numInPairs, int howManyElements, int startPend )
{
    if (startPend > howManyElements)
        startPend = howManyElements;

    size_t linkSize = link.size();
    size_t  pendSize = pend.size();
    std::list<t_link>::iterator it = link.begin();
    size_t  i = numInPairs / 2 - 1;

    for (; it != link.end(); it++)
    {
        if (it->bNumber == howManyElements)
            break ;
    }

    while (i < pendSize)
    {
        if (pend[i] == it->b)
            break ;
        i += numInPairs /2; // compare only lasts of pairs
    }

    i -= startPend * (numInPairs /2); // to put the i on the good start position

    while (pend[i] != it->b)
    {
        numsToInsert.push_back(pend[i]);
        pend.erase(pend.begin() + i, pend.begin() + (i + 1));
    }
    numsToInsert.push_back(pend[i]);
    pend.erase(pend.begin() + i, pend.begin() + (i + 1));
}

/* newPend is only the numbers to insert filled in the fillNumsToInsert function*/
void    insertElements( std::deque<int> &sequence, std::deque<int> &newPend, std::list<t_link> &link, size_t numInPairs )
{
    size_t linkSize = link.size();
    size_t  newPendSize = newPend.size() - 1;

    for (size_t i = newPendSize; )
}

void    startInsertion( std::deque<int> &sequence, std::deque<int> &pend, size_t numInPairs, std::list<t_link> &link )
{
    std::deque<int> jacobstahlNumbers;
    size_t  pendSize = pend.size();
    size_t  inserted = 0;

    initialiseJacobstahlNumbers(jacobstahlNumbers);

    for (size_t i = 3; i < jacobstahlNumbers.size() && inserted < pendSize; i++)
    {
        int howManyElements = jacobstahlNumbers[i] - jacobstahlNumbers[i - 1];
        int toInsert = std::min<int>(howManyElements, pendSize - inserted);
        std::deque<int> numsToInsert;
        
        fillNumsToInsert(numsToInsert, link, pend, numInPairs, toInsert, jacobstahlNumbers[i]);
        insertElements(sequence, numsToInsert, link, numInPairs);
        inserted += toInsert * (numInPairs /2);
    }

    
    
}
// if (pendSize <= numInPairs) // when pend is only with two elements or less
//         insertSimpleElements(sequence, pend, link, numInPairs);

int sortNumbers( std::deque<int>& sequence, int recursionlvl, size_t numInPairs )
{
    size_t  sequenceSize = sequence.size();

    compairPairs( sequence, numInPairs );
    
    if ((numInPairs * 2) <= sequenceSize)
        sortNumbers( sequence, recursionlvl + 1, numInPairs * 2 );

    if (numInPairs * 2 > sequenceSize)
        return (0);

    std::deque<int>     pend;
    std::list<t_link>   link;

    initialisePend(pend, sequence, numInPairs, link);

    startInsertion(sequence, pend, numInPairs, link);

    return (0);
}

int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cerr << "Error, wrong number of arguments" << std::endl;
        return (1);
    }

    std::deque<int> sequence;
    int             time;

    std::cout << "Before: ";
    for (int i = 1; i < ac; i++)
        std::cout << av[i] << " ";
    std::cout << std::endl;

    for (int i = 1; i < ac; i++)
    {
        int num = std::atoi(av[i]);
        if (num < 0)
        {
            std::cerr << "Error, a number is negative" << std::endl;
            return (1);
        }
        sequence.push_back(num);
    }

    time = sortNumbers(sequence, 1, 2);

    std::cout << time << std::endl;

    return (0);
}