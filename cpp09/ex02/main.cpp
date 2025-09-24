/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bproton <bproton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 17:11:48 by proton            #+#    #+#             */
/*   Updated: 2025/09/24 15:47:20 by bproton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void    swapElements( std::deque<int> &sequence, size_t index, size_t numInPair)
{
    for (size_t i = index; i < numInPair; i++)
    {
        if ()
    }
}

void    compairPairs( std::deque<int>&sequence, std::deque<std::pair<int, int>> &pairs, size_t numInPair )
{
    size_t sequenceSize = sequence.size();

    for (size_t i = 0; i < sequenceSize; i+=numInPair)
    {
        if (sequence[i + numInPair / 2] > sequence[i + numInPair - 1])
            swapElements( sequence, numInPair, i );
    }
}

int sortNumbers( std::deque<int>& sequence, int recursionlvl, size_t numInPairs )
{
    std::deque<std::pair<int, int>> pairs;
    size_t  sequenceSize = sequence.size();

    for (size_t i = 0; i < sequenceSize; i+=2)
        pairs.push_back(std::pair<int, int>(sequence[i], sequence[i + 1]));

    compairPairs( sequence, pairs, numInPairs );
    
    if ((numInPairs * 2) < (sequenceSize / 2))
        sortNumbers( sequence, recursionlvl + 1, numInPairs * 2 );
    
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
    for (size_t i = 1; i < ac; i++)
        std::cout << av[i] << " ";
    std::cout << std::endl;

    for (size_t i = 1; i < ac; i++)
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

    
}