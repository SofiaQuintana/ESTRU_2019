#include "QueryDriver.hpp"

QueryDriver::QueryDriver() {
    this -> initial = 0;
    this -> found = 0;
}

/* Elimina las palabras que no sean de utilidad en cualquier query */
vector<string> QueryDriver::removeWords(string query, string first, string second, string third) {
    vector<string> words = split(replace(query));
    int x = 0;
    
    for(int i = 0; i < words.size(); i++) {
        if(words[i] == first) {
            words.erase(words.begin() + i);
            i--;
        } else if(words[i] == second) {
            words.erase(words.begin() + i);
            i--;
        } else if(words[i] == third) {
            words.erase(words.begin() + i);
            i--;
        } else if(words[i] == "") {
            words.erase(words.begin() + i);
            i--;
        }
    }
    
    return words;
}

/* Elimina palabras que no sean de utilidad en la query 
 * utilizada para crear una tabla */
vector<string> QueryDriver::tableWords(string query) {
    return removeWords(query, " ", "CREATE", "TABLE");
}

/* Elimina palabras que no sean de utilidad en la query
 * utilizada para realizar una insercion */
vector<string> QueryDriver::insertWords(string query) {
    return removeWords(query, "INSERT", "INTO", "VALUES");
}

/* Elimina palabras que no sean de utilidad en la query
 * utilizada para realizar una seleccion de datos */
vector<string> QueryDriver::selectWords(string query) {
    return removeWords(query, "SELECT", "FROM", "WHERE");
}

string QueryDriver::replace(string query) {
    string symbol;
    for(int i = 0; i < 8; i++){
        switch(i){
            case 0: symbol = "\n"; break;
            case 1: symbol = "\r"; break;
            case 2: symbol = "\t"; break;
            case 3: symbol = "("; break;
            case 4: symbol = ")"; break;
            case 5: symbol = ","; break;
            case 6: symbol = "'"; break;
            case 7: symbol = "="; break;
        }
        position = 0;
        while ((position = query.find(symbol, position)) < string::npos){
            query.replace(position, 1, " ");
            position+=1;
        }
    }
    return query;
}

vector<string> QueryDriver::split(string query) {
    this -> initial = 0;
    this -> found = 0;
    vector<string> words;
    while(found >= 0) {
        found = query.find(" ", initial);
        splitted = query.substr(initial, found - initial);
        initial = found + 1;
        words.push_back(splitted);
    }
    return words;
}

QueryDriver::~QueryDriver() {

}