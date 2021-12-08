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
		storage[person][TaskStatus::NEW]++;
	}

	tuple<TasksInfo, TasksInfo> PerformPersonTasks(const string& person, int task_count) {
		if (storage.find(person) == storage.end())
			return { {},{} };
		TaskStatus task = TaskStatus::NEW;
		TasksInfo updatedTasks, untouchedTasks;
		untouchedTasks = storage[person];
		untouchedTasks.erase(TaskStatus::DONE);
		bool is_tasksEnd = false;
		while (task_count--) {
			switch (task)
			{
			case TaskStatus::NEW:
				if (storage[person][TaskStatus::NEW] != 0) {
					storage[person][TaskStatus::NEW]--;
					storage[person][TaskStatus::IN_PROGRESS]++;
					untouchedTasks[TaskStatus::NEW]--;
					updatedTasks[TaskStatus::IN_PROGRESS]++;
				}
				else {
					task = TaskStatus::IN_PROGRESS;
					task_count++;
					untouchedTasks.erase(TaskStatus::NEW);
				}
				break;
			case TaskStatus::IN_PROGRESS:
				if (storage[person][TaskStatus::IN_PROGRESS] != 0) {
					storage[person][TaskStatus::IN_PROGRESS]--;
					storage[person][TaskStatus::TESTING]++;
					untouchedTasks[TaskStatus::IN_PROGRESS]--;
					updatedTasks[TaskStatus::TESTING]++;
				}
				else {
					task = TaskStatus::TESTING;
					task_count++;
					untouchedTasks.erase(TaskStatus::IN_PROGRESS);
				}
				break;
			case TaskStatus::TESTING:
				if (storage[person][TaskStatus::TESTING] != 0) {
					storage[person][TaskStatus::TESTING]--;
					storage[person][TaskStatus::DONE]++;
					untouchedTasks[TaskStatus::TESTING]--;
					updatedTasks[TaskStatus::DONE]++;
				}
				else {
					task = TaskStatus::DONE;
					untouchedTasks.erase(TaskStatus::TESTING);
					is_tasksEnd = true;
				}
				break;
			case TaskStatus::DONE:
			default:
				break;
			}
			if (is_tasksEnd == true) break;
		}

		return { updatedTasks, untouchedTasks};
	}

private:
	map<string, TasksInfo> storage;

};

void PrintTasksInfo(TasksInfo info) {
	cout << info[TaskStatus::NEW] << " new tasks" << " , " <<
		info[TaskStatus::IN_PROGRESS] << " tasks in progress" << " , " <<
		info[TaskStatus::TESTING] << " tasks are been testing" << " , " <<
		info[TaskStatus::DONE] << " tasks are been done" << endl;
}

int main()
{
	try {
		TeamTasks tasks;
		TasksInfo info;
		tasks.AddNewTask("Ilia");
		tasks.AddNewTask("Ivan");
		tasks.AddNewTask("Ivan");
		tasks.AddNewTask("Ivan");
		cout << "Ilia's tasks: ";
		PrintTasksInfo(tasks.GetPersonalTaskInfo("Ilia"));
		cout << "Ivan's tasks: ";
		PrintTasksInfo(tasks.GetPersonalTaskInfo("Ivan"));

		TasksInfo updated_tasks, untouched_tasks;

		tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Ivan", 2);
		cout << "Updated Ivan's tasks: ";
		PrintTasksInfo(updated_tasks);
		cout << "Untouched Ivan's tasks: ";
		PrintTasksInfo(untouched_tasks);

		tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Ivan", 2);
		cout << "Updated Ivan's tasks: ";
		PrintTasksInfo(updated_tasks);
		cout << "Untouched Ivan's tasks: ";
		PrintTasksInfo(untouched_tasks);

	} catch (exception& e) {
		cout << e.what() << endl;
	}
	
	return 0;
}