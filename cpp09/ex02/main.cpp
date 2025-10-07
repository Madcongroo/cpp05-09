/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 17:11:48 by proton            #+#    #+#             */
/*   Updated: 2025/10/07 10:03:24 by proton           ###   ########.fr       */
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

// void    printsequence(std::deque<int> &sequence)
// {
//     for (size_t i = 0; i < sequence.size(); i++)
//         std::cout << sequence[i] << " ";
//     std::cout << std::endl;
// }

// /* newPend is only the numbers to insert filled in the fillNumsToInsert function*/
// void    insertElements( std::deque<int> &sequence, std::deque<int> &newPend, std::list<t_link> &link, size_t numInPairs )
// {
//     size_t  newPendSize = newPend.size();
//     std::list<t_link>::iterator it = link.begin();

//     std::cout << "in insert elements" << std::endl;

//     for (size_t i = newPendSize - 1; i > 0;)
//     {
//         // std::cout << "1" << std::endl;
//         for (;it != link.end(); it++)
//         {
//             // std::cout << "2" << std::endl;
//             if (it->b == newPend[i])
//                 break ;
//         }
//         // std::cout << "3" << std::endl;
//         if (it->a == -1)
//         {
//             // std::cout << "4" << std::endl;
//             for (size_t temp = numInPairs /2 -1; temp < sequence.size(); temp += numInPairs /2)
//             {
//                 if (temp + numInPairs /2 > sequence.size()) // if there are not used numbers, last number of pairs is the new a
//                     it->a = sequence[temp];
//             }
//             // std::cout << "5" << std::endl;
//             if (it->a == -1) // if the size of the sequence is the same as the one with pairs
//                 it->a = sequence[sequence.size() -1];
//             // std::cout << "6" << std::endl;
//         }
//         // std::cout << "7" << std::endl;
//         for (size_t j = numInPairs / 2 - 1; sequence[j] != it->a && j < sequence.size();) // je dois regarder pour si le a == -1, si il est a -1 je dois chercher dans toute la sequence main mais sans compter les nombres qui restent
//         {
//             int first;
//             int next;
//             if (j + numInPairs /2 > sequence.size())
//                 next = sequence[j];
//             else
//                 next = sequence[j + numInPairs / 2];
//             first = sequence[j];
            
//             if (first == next) // means that the sequence can only be placed at the end of main
//             {
//                 std::cout << "in first == next" << std::endl;
//                 int temptemp = 0;
//                 std::deque<int>::iterator itM = sequence.begin();
//                 for (; itM < sequence.end(); itM++)
//                 {
//                     if (*itM == first)
//                         break ;
//                 }
//                 size_t b = i - numInPairs /2 + 1; // pour lui donner l index du premier des la newpend que je dois actuellement inserer
//                 while (b < numInPairs /2)
//                 {
//                     sequence.insert(itM, newPend[i]);
//                     newPend.erase(newPend.begin() + i, newPend.begin() + (i + 1));
//                     itM++;
//                     b++;
//                 }
//                 temptemp++;
//                 if (temptemp == 1)
//                     exit(1);
//             }
//             if (newPend[i] > first && newPend[i] < next)
//             {
//                 std::cout << "in insert good position " << std::endl;
//                 std::deque<int>::iterator itMain = sequence.begin();
//                 for (; itMain != sequence.end(); itMain++)
//                 {
//                     if (*itMain == first)
//                         break ;
//                 }
//                 size_t a = 0; // pour lui donner l index du premier des la newpend que je dois actuellement inserer
//                 while (a < numInPairs /2)
//                 {
//                    sequence.insert(itMain, newPend[i]);
//                    newPend.erase(newPend.begin() + i, newPend.begin() + (i + 1));
//                    itMain++;
//                    a++;
//                 }
//                 printsequence(sequence);
//             }
//             // std::cout << "8" << std::endl;
//             j += numInPairs /2;
//         }
//         newPendSize -= numInPairs / 2;
//     }
// }

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

void    makeLink( std::deque<int> &sequence, std::list<t_link> &link )
{
    size_t j = 1;

    for (size_t i = 0; i < sequence.size(); i += 2)
    {
        t_link temp;
        temp.a = sequence[i];
        if (i + 1 >= sequence.size())
            temp.b = -1;
        else
            temp.b = sequence[i + 1];
        temp.bNumber = j;
        link.push_back(temp);
        j++;
    }
    for(size_t i = 0; i < sequence.size(); i++)
        std::cout << sequence[i] << " ";
    std::cout << ": sequence after sort" << std::endl;

    for(std::list<t_link>::iterator it = link.begin(); it != link.end(); it++)
    {
        std::cout << "a : " << it->a << " ";
        std::cout << "b : " << it->b << " ";
        std::cout << "bNumber : " << it->bNumber << std::endl;
    }

}


void    separatePairs( std::deque<int> &sequence, std::deque<int> &pend )
{
    std::deque<int> newMain;
    size_t n = sequence.size();

    for (size_t i = 0; i + 1 < n; i += 2)
    {
        int a = std::min(sequence[i], sequence[i + 1]);
        int b = std::max(sequence[i], sequence[i + 1]);
        newMain.push_back(a);
        pend.push_back(b);
    }

    if (n % 2 != 0)
        newMain.push_back(sequence.back());
        
    sequence = newMain;
}

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

void    compairPairs( std::deque<int>&sequence )
{
    size_t sequenceSize = sequence.size();

    for (size_t i = 0; i < sequenceSize; i+=2)
    {
        if (sequence[i] > sequence[i + 1]) // pour savoir si le dernier nombre de chaque pair est plus petit ou plus grand que le dernier nombre de la pair suivante
            swapElements( sequence, i, 2 );
    }
}

void    insertPend( std::deque<int> &sequence, std::deque<int> &pend, std::list<t_link> &link )
{
    
}

int sortNumbers( std::deque<int>& sequence, int recursionlvl, size_t pairSize )
{
    size_t  sequenceSize = sequence.size();
    size_t  odd = 0;
    std::deque<int> pend;
    std::list<t_link>   link;

    // std::cout << "RECUSTION LVL " << recursionlvl << std::endl;

    // for(size_t i = 0; i < sequence.size(); i++)
    //     std::cout << sequence[i] << " ";
    // std::cout << ": full sequence before sort" << std::endl;

    compairPairs(sequence);

    makeLink(sequence, link);


    // for(size_t i = 0; i < sequence.size(); i++)
    //     std::cout << sequence[i] << " ";
    // std::cout << ": full sequence after sort" << std::endl;
    separatePairs(sequence, pend);

    if (sequence.size() > 2)
        sortNumbers(sequence, recursionlvl +1, pairSize);

    insertPend(sequence, pend, link);

    // for(size_t i = 0; i < sequence.size(); i++)
    //     std::cout << sequence[i] << " ";
    // std::cout << ": main" << std::endl;
    
    // for(size_t i = 0; i < pend.size(); i++)
    //     std::cout << pend[i] << " ";
    // std::cout << ": pend" << std::endl;

    // if (sequenceSize > 2)
    //     sortNumbers( sequence, recursionlvl + 1, pairSize );

    

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

    // for (size_t i = 0; i < sequence.size(); i++)
    //     std::cout << sequence[i] << " ";
    // std::cout << std::endl;

    std::cout << time << std::endl;

    return (0);
}