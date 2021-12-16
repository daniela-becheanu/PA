#include <bits/stdc++.h>
using namespace std;

/* Structure that contains the name of a person and the its emails */
struct person {
    string name;
    set<string> emails;
};

/* Functions used to sort the people in the specified order */
bool cmp_people(const person &p1, const person &p2) {
    if (p1.emails.size() != p2.emails.size()) {
        return p1.emails.size() < p2.emails.size();
    }
    return strcmp(p1.name.c_str(), p2.name.c_str()) < 0;
}

int main() {
    /* Declare variables */
    int N, K, ok;
    vector<person> people;
    person curr_person;
    string name, email;

    /* Open input and output files */
    ifstream input("adrese.in");
    ofstream output("adrese.out");

    input >> N;

    /* Store the elements from the input file in a vector */
    for (int i = 0; i < N; ++i) {
        input >> curr_person.name >> K;
        curr_person.emails.clear();

        for (int j = 0; j < K; ++j) {
            input >> email;
            curr_person.emails.insert(email);
        }
        people.push_back(curr_person);
    }

    /* Close input file */
    input.close();

    for (int i = 0; i < people.size() - 1; ++i) {
cont:
        for (int j = i + 1; j < people.size(); ++j) {
            for (auto email : people[i].emails) {
                /* If there is an email at two people, put the emails in the
                 * vector corresponding to the one lower lexicogrphically and
                 * delete the one with the higher name lexicographically */
                if (people[j].emails.find(email) != people[j].emails.end()) {
                    if (strcmp(people[i].name.c_str(),
                               people[j].name.c_str()) > 0) {
                        for (auto mail : people[i].emails) {
                            people[j].emails.insert(mail);
                        }
                        people.erase(people.begin() + i);
                    } else {
                        for (auto mail : people[j].emails) {
                            people[i].emails.insert(mail);
                        }
                        people.erase(people.begin() + j);
                    }
                    goto cont;
                }
            }
        }
    }

    /* Sort the people in the disired order and print them how it is asked */
    sort(people.begin(), people.end(), cmp_people);

    output << people.size() << endl;
    for (int i = 0; i < people.size(); ++i) {
        output << people[i].name << " " << people[i].emails.size() << endl;
        for (auto email : people[i].emails) {
            output << email << endl;
        }
    }

    /* Close the output file */
    output.close();
}
