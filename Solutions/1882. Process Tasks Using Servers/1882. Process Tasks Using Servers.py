class Solution:
    def assignTasks(self, servers: List[int], tasks: List[int]) -> List[int]:
        res=[]
        avail=[[weight,i,0] for i,weight in enumerate(servers)]
        heapq.heapify(avail)
        busy=[]
        for i in range(len(tasks)):
            t=tasks[i]
            #try to free server
            while busy and busy[0][0]<=i:
                time,weight,index=heapq.heappop(busy)
                heapq.heappush(avail,[weight,index,time])
            if len(avail)==0:
                time,weight,index=heapq.heappop(busy)
                res.append(index)
                time+=t
                heapq.heappush(busy,[time,weight,index])
            else:
                weight,index,time=heapq.heappop(avail)
                res.append(index)
                time=t+i
                heapq.heappush(busy,[time,weight,index])
        return res
            