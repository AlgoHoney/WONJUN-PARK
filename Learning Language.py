from typing import List
from collections import deque

def bfs(employees: List[List[int]], start: int):
    global answer

    queue = deque([start])
    visited[start] = True

    while queue:
        v = queue.popleft()

        for language in employees[v]:
            for i in range(n):
                if visited[i]:
                    continue

                if employees[i].count(language):
                    visited[i] = True
                    queue.append(i)

    if visited.count(False):
        idx = visited.index(False)
        bfs(employees, idx)
        answer += 1

    return

n, m = map(int, input().split())

employees: List[List[int]] = []
for i in range(n):
    employee = list( map( int, input().split()))
    employee = employee[1:len(employee)]
    employees.append(employee)


visited = [False] * len(employees)
answer = 0

bfs(employees, 0)
print(answer)
