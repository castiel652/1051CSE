#include <iostream>
#include <string>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
	int team[1000000], teams, member, membercount, k = 0;
	list<int> tqueue, emptyuse; 
	/* 
	 * if there is no teammember in queue, the position will 
	 * be pointed to emptyuse
	 */
	string command;
	while(1) {
		fill_n(team, 100 ,0); /*team saves the number's team*/
		cin >> teams;
		if(teams == 0)
			break;
		tqueue.clear();
		list<int>::iterator teampos[teams];/*team member's position*/
		for(int i = 0; i < teams; ++i) {
			cin >> membercount;
			for(int j = 0; j < membercount; ++j) {
				cin >> member;
				team[member] = i;
			}
		}
		cout << "Scenario #" << ++k << endl;
		for(int i = 0; i < teams; ++i)
			teampos[i] = emptyuse.end();
		while(1) {
			cin >> command;
			/*
			 *ENQUEUE: if the positon is pointed to emptyuse
			 *push the element to the last and pos++
			 */
			if(command == "STOP")
				break;
			else if(command == "ENQUEUE") {
				cin >> member;
				if(teampos[team[member]] == emptyuse.end()) {
					tqueue.push_back(member);
					teampos[team[member]] = tqueue.end();
					teampos[team[member]]--;

				}
				else {
					teampos[team[member]]++;
					tqueue.insert(teampos[team[member]], member);
					teampos[team[member]]--;
				}
			}
			else {
				int out = tqueue.front();
				cout << out << endl;
				/*
				 * if the last member is printed,
				 * position will be pointed to emptyuse
				 */
				list<int>::iterator it = tqueue.begin();
				if(it == teampos[team[*it]])
					teampos[team[*it]] = emptyuse.end();
				tqueue.pop_front();
			}
		}
		cout << endl;
	}
	return 0;
}
