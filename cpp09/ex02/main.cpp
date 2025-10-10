/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 17:11:48 by proton            #+#    #+#             */
/*   Updated: 2025/10/10 19:57:45 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template <typename Container>
void separatePairs( Container &sequence, Container &pend, std::list<t_link> &links )
{
    Container newMain;
    size_t n = sequence.size();
    int bNumber = 1;

    for (size_t i = 0; i + 1 < n; i += 2)
    {
        int x = sequence[i];
        int y = sequence[i + 1];
        int a = std::min(x, y);
        int b = std::max(x, y);

        newMain.push_back(a);
        pend.push_back(b);

        t_link link;
        link.bNumber = bNumber++;
        link.a = a;
        link.b = b;
        links.push_back(link);
    }

    if (n % 2 != 0)
        newMain.push_back(sequence.back());

    sequence = newMain;
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
}

template <typename Container>
void insertNumber( Container &sequence, Container &pend, std::list<t_link> &link, int pendIdx )
{
    if (pendIdx < 0 || pendIdx >= (int)pend.size())
        return;

    std::list<t_link>::iterator it = link.begin();
    int val = pend[pendIdx];
    for (; it != link.end(); ++it)
    {
        if (it->b == val)
            break;
    }
    if (it == link.end())
        return;

    size_t mainIdx = 0;
    while (mainIdx < sequence.size() && sequence[mainIdx] != it->a)
        mainIdx++;
    if (mainIdx == sequence.size())
        return;

    int value = pend[pendIdx];

    for (; mainIdx < sequence.size(); ++mainIdx)
    {
        int current = sequence[mainIdx];
        int next = (mainIdx + 1 < sequence.size()) ? sequence[mainIdx + 1] : INT_MAX;

        if (value > current && value < next)
        {
            sequence.insert(sequence.begin() + mainIdx + 1, value);
            pend.erase(pend.begin() + pendIdx);
            return;
        }
    }

    sequence.push_back(value);
    pend.erase(pend.begin() + pendIdx);
}

template <typename Container>
void    insertPend( Container &sequence, Container &pend, std::list<t_link> &link )
{
    std::deque<int> jacobstahl;
    initialiseJacobstahlNumbers(jacobstahl);

    size_t jacIdx = 0;
    for (jacIdx = 0; jacIdx < jacobstahl.size(); jacIdx++)
    {
        if ((size_t)jacobstahl[jacIdx] > pend.size())
        {
            jacIdx--;
            break ;
        }
    }
    for (; jacIdx > 0; jacIdx--)
    {
        int pendIdx = jacobstahl[jacIdx] - 1;
        if (pendIdx < 0 || pendIdx >= (int)pend.size())
            continue;
        insertNumber(sequence, pend, link, pendIdx);
    }

    size_t i = 0;
    for (; !pend.empty(); i++)
        insertNumber(sequence, pend, link, 0);
}

template <typename Container>
double sortNumbers( Container &sequence, int recursionlvl, size_t pairSize )
{
    Container pend;
    std::list<t_link>   link;
    std::clock_t start = std::clock();
    

    separatePairs(sequence, pend, link);


    if (sequence.size() >= 2)
        sortNumbers(sequence, recursionlvl +1, pairSize);

    insertPend(sequence, pend, link);

    std::clock_t end = std::clock();

    double elapsed = double(end - start) / CLOCKS_PER_SEC;

    return (elapsed);
}


int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cerr << "Error, wrong number of arguments" << std::endl;
        return (1);
    }

    std::deque<int> sequence;

    std::vector<int> sequenceVec;

    for (int i = 1; i < ac; i++)
    {
        int num = std::atoi(av[i]);
        if (num < 0)
        {
            std::cerr << "Error, a number is negative" << std::endl;
            return (1);
        }
        sequence.push_back(num);
        sequenceVec.push_back(num);
    }
    if (std::set<int>(sequenceVec.begin(), sequenceVec.end()).size() != sequenceVec.size())
    {
        std::cerr << "No duplicates allowed" << std::endl;
        return (1);
    }

    std::cout << "with std::deque : " << sortNumbers(sequence, 1, 2) << std::endl;

    std::cout << "with std::vector : " << sortNumbers(sequenceVec, 1, 2) << std::endl;

    for (size_t i = 0; i < sequence.size(); i++)
        std::cout << sequence[i] << " ";
    std::cout << std::endl;

    for (size_t i = 0; i < sequence.size(); i++)
        std::cout << sequenceVec[i] << " ";
    std::cout << std::endl;

    return (0);
}