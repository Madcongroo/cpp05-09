/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 17:11:48 by proton            #+#    #+#             */
/*   Updated: 2025/10/02 13:40:42 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// void swapElements(std::deque<int> &sequence, size_t index, size_t numInPair)
// {
//     if (index + numInPair > sequence.size() || numInPair % 2 != 0)
//     {
//         std::cerr << "Erreur: bloc invalide pour swap" << std::endl;
//         return;
//     }

//     size_t half = numInPair / 2;

//     std::deque<int>::iterator first  = sequence.begin() + index;
//     std::deque<int>::iterator middle = first + half;
//     std::deque<int>::iterator last   = first + numInPair;

//     std::rotate(first, middle, last);
// }

// void    compairPairs( std::deque<int>&sequence, size_t numInPair )
// {
//     size_t sequenceSize = sequence.size();

//     for (size_t i = 0; i < sequenceSize; i+=numInPair)
//     {
//         if (sequence[i + numInPair / 2 - 1] > sequence[i + numInPair - 1]) // pour savoir si le dernier nombre de chaque pair est plus petit ou plus grand que le dernier nombre de la pair suivante
//             swapElements( sequence, i, numInPair );
//     }
// }

// void    linkPairs( std::deque<int> &sequence, std::list<t_link> &link, size_t numInPairs )
// {
//     size_t sequenceSize = sequence.size();
//     int  bNumber = 2; // the pend will never have b1, so i start with 2 (b2)

//     for (size_t i = numInPairs; i < sequenceSize; )
//     {
//         t_link  tempLink;

//         if (i + numInPairs > sequenceSize && (i + numInPairs / 2) < sequenceSize)
//         {
//             tempLink.bNumber = bNumber++;
//             tempLink.b = sequence[i + (numInPairs / 2 - 1)];
//             tempLink.a = -1;
//             link.push_back(tempLink);
//             break ;
//         }

//         tempLink.bNumber = bNumber++;
//         tempLink.b = sequence[i + (numInPairs / 2 - 1)];
//         tempLink.a = sequence[i + (numInPairs - 1)];
//         link.push_back(tempLink);
//         if (i + numInPairs > sequenceSize)
//             break ;
//         i += numInPairs;
//     }
//     for (size_t i = 0; i < sequence.size(); i++)
//     {
//         std::cout << sequence[i] << " ";
//     }
//     std::cout << std::endl;
//     std::cout << "LIST SIZE == " << link.size() << std::endl;
//     for (std::list<t_link>::const_iterator it = link.begin(); it != link.end(); ++it)
//     {
//         std::cout << "bNumber is : " << it->bNumber << std::endl;
//         std::cout << "b is : " << it->b << std::endl;
//         std::cout << "a is : " << it->a << std::endl;
//     }
// }

// void initialisePend( std::deque<int> &pend, std::deque<int> &sequence, size_t numInPair, std::list<t_link> &link )
// {
//     size_t sequenceSize = sequence.size();
//     size_t startIndex = numInPair;

//     std::cout << "NUM IN PAIR " << numInPair << std::endl;

//     linkPairs(sequence, link, numInPair); // to link pairs (b, a) with indexes of the last number of (b, a)

//     for (size_t i = startIndex; (i + numInPair / 2) <= sequenceSize; i++)
//     {
//         size_t j = 0;
//         while (j < numInPair / 2)
//         {
//             pend.push_back(sequence[i]);
//             sequence.erase(sequence.begin() + i, sequence.begin() + (i + 1));
//             j++;
//         }
//         i += numInPair / 2 - 1;

//         sequenceSize -= numInPair / 2;
//     }
// }

// int findInLink( int pendNumber, std::list<t_link> &link )
// {
//     for (std::list<t_link>::iterator it = link.begin(); it != link.end(); it++)
//     {
//         if (pendNumber == it->b)
//             return (it->a);
//     }
//     return (-1);
// }

// void    initialiseJacobstahlNumbers( std::deque<int> &jacobstahlNumbers )
// {
//     jacobstahlNumbers.push_back(1);
//     jacobstahlNumbers.push_back(1);

//     size_t i = 2;
//     while (true)
//     {
//         size_t next = jacobstahlNumbers[i - 1] + 2 * jacobstahlNumbers[i - 2];
//         if (next > 5461)
//             break ;
//         jacobstahlNumbers.push_back(next);
//         i++;
//     }
//     jacobstahlNumbers.pop_front(); // removing the first 1, because we dont need it
// }

// /*start pend is the supposed number to start with (on the jacobastahl sequence)
// if the number of elements to insert is */
// void    fillNumsToInsert(std::deque<int> &numsToInsert, std::list<t_link> &link, std::deque<int> &pend, size_t numInPairs, int howManyElements, int startPend )
// {
//     size_t  pendSize = pend.size();
//     std::list<t_link>::iterator it = link.begin();
//     size_t  i = numInPairs / 2 - 1;

//     if (startPend > howManyElements)
//         it = link.end();
//     else
//     {
//         for (; it != link.end(); it++)
//         {
//             if (it->bNumber == startPend)
//                 break ;
//         }
//     }

//     while (i < pendSize)
//     {
//         if (pend[i] == it->b)
//             break ;
//         i += numInPairs /2; // compare only lasts of pairs
//     }

//     i -= startPend * (numInPairs /2) - 1; // to put the i on the good start position

//     std::deque<size_t> indicesToRemove;

//     while (i < pend.size() && pend[i] != it->b)
//     {
//         numsToInsert.push_back(pend[i]);
//         indicesToRemove.push_back(i);
//         ++i;
//     }

//     for (std::deque<size_t>::reverse_iterator rit = indicesToRemove.rbegin();
//         rit != indicesToRemove.rend(); ++rit)
//     {
//         pend.erase(pend.begin() + *rit);
//     }
// }

// // Génère la séquence de Jacobsthal
// std::vector<size_t> generateJacobsthalSequence(size_t max) {
//     std::vector<size_t> jacobsthal;
//     size_t j1 = 1;
//     size_t j2 = 1;
    
//     while (j2 <= max) {
//         jacobsthal.push_back(j2);
//         size_t temp = j2;
//         j2 = j2 + 2 * j1;
//         j1 = temp;
//     }
    
//     return jacobsthal;
// }

// // Crée l'ordre d'insertion basé sur Jacobsthal
// std::vector<size_t> createInsertionOrder(size_t pendSize, size_t pairSize) {
//     size_t numPairs = pendSize / pairSize;
//     std::vector<size_t> order;
    
//     if (numPairs == 0)
//         return order;
    
//     std::vector<size_t> jacobsthal = generateJacobsthalSequence(numPairs);
//     std::vector<bool> used(numPairs, false);
    
//     size_t prevJacob = 0;
//     for (size_t jIdx = 0; jIdx < jacobsthal.size(); ++jIdx) {
//         size_t jacob = jacobsthal[jIdx];
//         if (jacob > numPairs)
//             jacob = numPairs;
        
//         // Insérer en ordre décroissant entre prevJacob et jacob
//         for (size_t i = jacob; i > prevJacob; --i) {
//             if (!used[i - 1]) {
//                 order.push_back(i - 1);
//                 used[i - 1] = true;
//             }
//         }
//         prevJacob = jacob;
//     }
    
//     // Ajouter les éléments restants
//     for (size_t i = 0; i < numPairs; ++i) {
//         if (!used[i])
//             order.push_back(i);
//     }
    
//     return order;
// }

// // Trouve le lien correspondant à un élément b du pend
// std::list<t_link>::iterator findLink(std::list<t_link> &link, int b) {
//     std::list<t_link>::iterator it;
//     for (it = link.begin(); it != link.end(); ++it) {
//         if (it->b == b)
//             return it;
//     }
//     return link.end();
// }

// // Trouve la position limite dans la main sequence
// size_t findMaxSearchPos(std::deque<int> &sequence, int targetA, size_t pairSize) {
//     if (targetA == -1)
//         return sequence.size() / pairSize;  // chercher dans toute la main
    
//     // Chercher la position de targetA dans la sequence
//     for (size_t i = pairSize - 1; i < sequence.size(); i += pairSize) {
//         if (sequence[i] == targetA)
//             return (i / pairSize) + 1;  // retourne le nombre de paires jusqu'à targetA inclus
//     }
    
//     return sequence.size() / pairSize;
// }

// // Insère une paire du pend dans la main en utilisant binary search
// void insertPairIntoMain(std::deque<int> &sequence, std::deque<int> &newPend, 
//                        size_t pendPairIdx, size_t maxSearchPos, size_t pairSize) {
//     // Index du dernier élément de la paire dans newPend
//     size_t lastElemIdx = (pendPairIdx + 1) * pairSize - 1;
//     int valueToCompare = newPend[lastElemIdx];
    
//     size_t left = 0;
//     size_t right = maxSearchPos;
    
//     // Binary search pour trouver la position d'insertion
//     while (left < right) {
//         size_t mid = left + (right - left) / 2;
//         size_t compareIdx = (mid + 1) * pairSize - 1;
        
//         if (compareIdx < sequence.size() && sequence[compareIdx] < valueToCompare)
//             left = mid + 1;
//         else
//             right = mid;
//     }
    
//     // Position d'insertion en termes d'index dans la deque
//     size_t insertPos = left * pairSize;
    
//     // Insérer tous les éléments de la paire
//     size_t firstElemIdx = pendPairIdx * pairSize;
//     for (size_t i = 0; i < pairSize; ++i) {
//         sequence.insert(sequence.begin() + insertPos + i, newPend[firstElemIdx + i]);
//     }
// }

// void insertElements(std::deque<int> &sequence, std::deque<int> &newPend, 
//                    std::list<t_link> &link, size_t numInPairs) {
//     if (newPend.empty())
//         return;
    
//     size_t pairSize = numInPairs / 2;
    
//     // Générer l'ordre d'insertion selon Jacobsthal
//     std::vector<size_t> insertionOrder = createInsertionOrder(newPend.size(), pairSize);
    
//     // Pour chaque paire à insérer selon l'ordre optimal
//     for (size_t idx = 0; idx < insertionOrder.size(); ++idx) {
//         size_t pairIdx = insertionOrder[idx];
        
//         // Trouver le dernier élément de la paire
//         size_t lastElemIdx = (pairIdx + 1) * pairSize - 1;
//         int b = newPend[lastElemIdx];
        
//         // Trouver le lien correspondant
//         std::list<t_link>::iterator linkIt = findLink(link, b);
//         if (linkIt == link.end())
//             continue;
        
//         // Déterminer jusqu'où chercher dans la main
//         size_t maxSearchPos = findMaxSearchPos(sequence, linkIt->a, pairSize);
        
//         // Insérer la paire dans la main
//         insertPairIntoMain(sequence, newPend, pairIdx, maxSearchPos, pairSize);
//     }
// }

// // /* newPend is only the numbers to insert filled in the fillNumsToInsert function*/
// // void    insertElements( std::deque<int> &sequence, std::deque<int> &newPend, std::list<t_link> &link, size_t numInPairs )
// // {
// //     size_t  newPendSize = newPend.size();
// //     std::list<t_link>::iterator it = link.begin();

// //     for (size_t i = newPendSize - 1; i > 0;)
// //     {
// //         for (;it != link.end(); it++)
// //         {
// //             if (it->b == newPend[i])
// //                 break ;
// //         }
// //         if (it->a == -1)
// //         {
// //             for (size_t temp = numInPairs /2 -1; temp < sequence.size(); temp += numInPairs /2)
// //             {
// //                 if (temp + numInPairs /2 > sequence.size())
// //                     it->a = sequence[temp];
// //             }
// //         }
// //         for (size_t j = numInPairs / 2 - 1; sequence[j] != it->a;) // je dois regarder pour si le a == -1, si il est a -1 je dois chercher dans toute la sequence main mais sans compter les nombres qui restent
// //         {
// //             int first;
// //             int next;
// //             if (j + numInPairs /2 > sequence.size())
// //                 next = sequence[j];
// //             else
// //                 next = sequence[j + numInPairs / 2];
// //             first = sequence[j];
            
// //             // if (first == next) // means that the sequence can only be placed at the end of main
// //             // {
// //             //     int a = i - numInPairs /2 + 1; // pour lui donner l index du premier des la newpend que je dois actuellement inserer
// //             //     while (a < i + numInPairs /2)
// //             //     {
// //             //         sequence.insert()
// //             //     }
// //             // }
// //             if (newPend[i] > first && newPend[i] < next)
// //             {
// //                 std::deque<int>::iterator itMain = sequence.begin();
// //                 for (; itMain != sequence.end(); itMain++)
// //                 {
// //                     if (*itMain == sequence[j])
// //                         break ;
// //                 }
// //                 size_t a = 0; // pour lui donner l index du premier des la newpend que je dois actuellement inserer
// //                 while (a < numInPairs /2)
// //                 {
// //                    sequence.insert(itMain, newPend[i]);
// //                    newPend.erase(newPend.begin() + i, newPend.begin() + (i + 1));
// //                    itMain++;
// //                    a++;
// //                 }
// //             }
// //             j += numInPairs /2;
// //         }
// //         newPendSize -= numInPairs / 2;
// //     }
// // }

// void    startInsertion( std::deque<int> &sequence, std::deque<int> &pend, size_t numInPairs, std::list<t_link> &link )
// {
//     std::deque<int> jacobstahlNumbers;
//     size_t  pendSize = pend.size();
//     size_t  inserted = 0;

//     initialiseJacobstahlNumbers(jacobstahlNumbers);
//     for (size_t i = 0; i < jacobstahlNumbers.size(); i++)
//         std::cout << jacobstahlNumbers[i] << " ";
//     std::cout << std::endl;

//     for (size_t i = 1; i < jacobstahlNumbers.size() && inserted < pendSize; i++)
//     {
//         int howManyElements = jacobstahlNumbers[i] - jacobstahlNumbers[i - 1];
//         int toInsert = std::min<int>(howManyElements, pendSize - inserted);
//         std::deque<int> numsToInsert;
    
//         fillNumsToInsert(numsToInsert, link, pend, numInPairs, toInsert, jacobstahlNumbers[i]);
//         insertElements(sequence, numsToInsert, link, numInPairs);
//         inserted += toInsert * (numInPairs /2);
//     }

    
    
// }
// // if (pendSize <= numInPairs) // when pend is only with two elements or less
// //         insertSimpleElements(sequence, pend, link, numInPairs);

// int sortNumbers( std::deque<int>& sequence, int recursionlvl, size_t numInPairs )
// {
//     size_t  sequenceSize = sequence.size();

//     compairPairs( sequence, numInPairs );
    
//     if ((numInPairs * 2) <= sequenceSize)
//         sortNumbers( sequence, recursionlvl + 1, numInPairs * 2 );

//     if (numInPairs * 2 > sequenceSize)
//         return (0);

//     std::deque<int>     pend;
//     std::list<t_link>   link;

//     initialisePend(pend, sequence, numInPairs, link);

//     for (size_t i = 0; i < pend.size(); i++)
//         std::cout << pend[i] << " ";
//     std::cout << std::endl;

//     startInsertion(sequence, pend, numInPairs, link);
//     std::cout << "AFTER START INSERTION " << std::endl;

//     return (0);
// }
























int sortNumbers( std::deque<int>& sequence, int recursionlvl, size_t pairSize )
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

    for (size_t i = 0; i < pend.size(); i++)
        std::cout << pend[i] << " ";
    std::cout << std::endl;

    startInsertion(sequence, pend, numInPairs, link);
    std::cout << "AFTER START INSERTION " << std::endl;

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

    for (size_t i = 0; i < sequence.size(); i++)
        std::cout << sequence[i] << " ";
    std::cout << std::endl;

    std::cout << time << std::endl;

    return (0);
}