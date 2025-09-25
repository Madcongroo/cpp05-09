/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bproton <bproton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 17:11:48 by proton            #+#    #+#             */
/*   Updated: 2025/09/25 15:52:07 by bproton          ###   ########.fr       */
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

    for (size_t i = 0; i < sequenceSize; i++)
    {
        std::cout << sequence[i] << " ";
    }
    std::cout << std::endl;
}

void initialisePend( std::deque<int> &pend, std::deque<int> &sequence, size_t numInPair )
{
    size_t sequenceSize = sequence.size();
    size_t startIndex = numInPair;

    for (size_t i = startIndex; (i + numInPair) < sequenceSize; i++)
    {
        if (i - startIndex == numInPair / 2)
            i += sequenceSize;

        std::cout << "I - start index VALUE " << i - startIndex << std::endl;
        pend.push_back(sequence[i]);
        sequence.erase(sequence.begin() + i, sequence.begin() + (i + 1));
    //     for (size_t i = 0; i < sequence.size(); i++)
    // {
    //     std::cout << sequence[i] << " ";
    // }
    // std::cout << std::endl;

        sequenceSize -= 1;
    }

    std::cout << "IN PEND INITIALISATION " << std::endl;
    for (size_t i = 0; i < pend.size(); i++)
    {
        std::cout << pend[i] << " ";
    }
    std::cout << std::endl;

}

int sortNumbers( std::deque<int>& sequence, int recursionlvl, size_t numInPairs )
{
    size_t  sequenceSize = sequence.size();

    std::cout << "lvl of recursion before compair pairs " << recursionlvl << std::endl;
    compairPairs( sequence, numInPairs );
    
    std::cout << "NUM IN PAIRS IN MAIN FUNCTION <<<<<<<<<<<<<<" << numInPairs << std::endl;
    if ((numInPairs * 2) <= sequenceSize)
        sortNumbers( sequence, recursionlvl + 1, numInPairs * 2 );

    if (numInPairs * 2 > sequenceSize)
        return (0);

    std::deque<int> pend;

    std::cout << "LVL OF RECURSION " << recursionlvl << std::endl;

    initialisePend(pend, sequence, numInPairs);

    // std::cout << "RECUSION LVL : " << recursionlvl << ", sequence : ";
    // for (size_t i = 0; i < sequenceSize; i++)
    // {
    //     std::cout << sequence[i] << " ";
    // }
    // std::cout << std::endl;
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