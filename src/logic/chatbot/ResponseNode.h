/* 
 * File:   ResponseNode.h
 * Author: chris
 *
 * Created on July 22, 2014, 10:19 PM
 */

#ifndef RESPONSENODE_H
#define	RESPONSENODE_H

#include <vector>

using namespace std;

class ResponseNode {
private:
    /*
     * NOTE:
     * About matches: The number defined in *matches
     * defines how many words in a string need to match the ones
     * in primary and secondary words lists to activate this response node
     */
    vector<string> primaryWords; // List of words to match in primary
    vector<string> secondaryWords; // list of words to match in secondary
    int requiredPrimaryMatches; // number of required primary matches
    int requiredSecondaryMatches; // number of required secondary matches
    
    // Possible answers
    vector<string> positiveAnswers;
    vector<string> neutralAnswers;
    vector<string> negativeAnswers;
    
public:
    ResponseNode();
};

#endif	/* RESPONSENODE_H */

