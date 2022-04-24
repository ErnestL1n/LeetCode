type Pair struct {
    First,Second interface{}
}

type UndergroundSystem struct {
    // id-{stationName,Time}
    checkin map[int]Pair
    // road-{duration,count}
    checkout map[string]Pair
}


func Constructor() UndergroundSystem {
    checkin:=make(map[int]Pair)
    checkout:=make(map[string]Pair)
    return UndergroundSystem{checkin,checkout}
}


func (this *UndergroundSystem) CheckIn(id int, stationName string, t int)  {
    this.checkin[id]=Pair{stationName,t}
}


func (this *UndergroundSystem) CheckOut(id int, stationName string, t int)  {
    in:=this.checkin[id]
    road:=in.First.(string)+"-"+stationName
    duration:=this.checkout[road].First
    cnt:=this.checkout[road].Second
    if cnt==nil{
        cnt=1
    }else{
        cnt=cnt.(int)+1
    }
    if duration==nil{
        duration=t-in.Second.(int)   
    }else{
        duration=duration.(int)+t-in.Second.(int)
    }
    this.checkout[road]=Pair{duration,cnt}
}


func (this *UndergroundSystem) GetAverageTime(startStation string, endStation string) float64 {
    road:=startStation+"-"+endStation
    getduration:=this.checkout[road]
    return float64(getduration.First.(int))/float64(getduration.Second.(int))
}


/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * obj := Constructor();
 * obj.CheckIn(id,stationName,t);
 * obj.CheckOut(id,stationName,t);
 * param_3 := obj.GetAverageTime(startStation,endStation);
 */