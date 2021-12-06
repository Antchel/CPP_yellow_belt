#include <iostream>
#include <map>

using namespace std;

enum class TaskStatus {
	NEW,
	IN_PROGRESS,
	TESTING,
	DONE
};

using TasksInfo = map<TaskStatus, int>;

class TeamTasks {
public:
	const TasksInfo& GetPersonalTaskInfo(const string& person) const {
		return storage.at(person);
	}

	void AddNewTask(const string& person) {
		if (storage.find(person) == storage.end()) {
			storage[person] = { {TaskStatus::DONE, 0},
								{TaskStatus::IN_PROGRESS, 0},
								{TaskStatus::NEW, 0},
								{TaskStatus::TESTING, 0} };
		}
		storage[person][TaskStatus::NEW]++;
	}

	tuple<TasksInfo, TasksInfo> PerformPersonTasks(const string& person, int task_count) {
		return { {}, {} };
	}

private:
	map<string, TasksInfo> storage;

};

void PrintTasksInfo(const TasksInfo& info) {
	cout << info.at(TaskStatus::NEW) << " new tasks" << " , " <<
		info.at(TaskStatus::IN_PROGRESS) << " tasks in progress" << " , " <<
		info.at(TaskStatus::TESTING) << " tasks are been testing" << " , " <<
		info.at(TaskStatus::DONE) << " tasks are been done" << endl;
}

int main()
{
	try {
		TeamTasks tasks;
		TasksInfo info;
		tasks.AddNewTask("Ivan");
		tasks.AddNewTask("Ivan");
		tasks.AddNewTask("Ivan");
		PrintTasksInfo(tasks.GetPersonalTaskInfo("Ivan"));
	} catch (exception& e) {
		cout << e.what() << endl;
	}
	
	return 0;
}