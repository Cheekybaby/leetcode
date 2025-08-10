class Solution {
private:
    string processing(string &s){
        string t;
        for(int i=0; i<s.length(); i++){
            if (s[i] == '.') continue;
            else if (s[i] == '+') return t;
            t += s[i];
        }

        return t;
    }
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> unique_mails;

        for(int i=0; i<emails.size(); i++){
            string address = emails[i];
            // Find the '@'
            int j=0;
            while(j < address.length()){
                if (address[j] == '@') break;
                j++;
            }

            string local_name = address.substr(0, j);
            string last_name = address.substr(j);

            string unique_mail = processing(local_name) + last_name;
            
            cout << unique_mail << endl;
            unique_mails.insert(unique_mail);
        }

        return (int)unique_mails.size();
    }
};

/*
- So for every email address we have two parts:
    - the local name
    - the domain name
- For evey email address, we will process the local name first.
- Now the local name has two different rules in place:
    - If there is a '.' then it is just ignored.
    - If there is a '+' then everything to the right of it is ignored.

- Then we process the domain name, which has no rules in place, so we
    can just add this to our email address.
- Now every email address produced after these refinements are stored in a set.
- A set here makes sure only the uniques are stored.
- After processing every email, the size of the set is the number of unique emails we have, and that is the total number of emails that will be receiving the sent emails.

*/