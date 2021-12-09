class Solution {
    int r,c;
    set<pair<int,int>> res;
        
    vector<vector<bool>> visited;
     
    vector<vector<pair<bool,bool>>> connected;
 
    
public:
    void DFSOnDirection(int i,int j,int ni,int nj,vector<vector<int>>& heights)
    {
        if((connected[i][j] != pair<bool,bool>(true,true)) )
        {
            if( heights[ni][nj] <= heights[i][j])
            {
                if(!visited[ni][nj] )
                {
                    DFS(ni,nj,heights);
                }

                if(connected[ni][nj].first)
                    connected[i][j].first = true;
                if(connected[ni][nj].second)
                    connected[i][j].second = true;
            }
        }
    }
    //------------------------------------------------------------------------------
    void CheckEqualNeighbourAndMarkConnected(int i,int j,vector<vector<int>>& heights)
    {
        if(! visited[i][j] )
            return;
        
        connected[i][j].first = true;
        connected[i][j].second = true;
        
        res.insert(pair<int,int>(i,j));
        //---------------------------------------------------------------
        //left
        if(  (j-1 >= 0) &&  (heights[i][j-1] == heights[i][j]) )
        {
            if(connected[i][j-1] != pair<bool,bool>(true,true))
                CheckEqualNeighbourAndMarkConnected(i,j-1,heights);
        }
        //---------------------------------------------------------------
        //up
        if(  (i-1 >= 0) &&  (heights[i-1][j] == heights[i][j]) )
        {            
            if(connected[i-1][j] != pair<bool,bool>(true,true))
                CheckEqualNeighbourAndMarkConnected(i-1,j,heights);
        }
        
        //---------------------------------------------------------------
        //right
        if(  (j+1 < c ) &&  (heights[i][j+1] == heights[i][j]) )
        {
            if(connected[i][j+1] != pair<bool,bool>(true,true))
                CheckEqualNeighbourAndMarkConnected(i,j+1,heights);
        }
        //---------------------------------------------------------------
        //down
        if(  (i+1 < r) &&  (heights[i+1][j] == heights[i][j]) )
        {
            if(connected[i+1][j] != pair<bool,bool>(true,true))
                CheckEqualNeighbourAndMarkConnected(i+1,j,heights);
        }
    }
    
    //------------------------------------------------------------------------------
    void DFS(int i,int j,vector<vector<int>>& heights)
    {
        if(i<0 || i>= heights.size() || j<0 || j>= heights[0].size() || visited[i][j]  )
            return;
        
        visited[i][j] = true;
        
        //(0,n-1) and (n-1,0) and for true elements
        if(connected[i][j] == pair<bool,bool>(true,true))
        {
            CheckEqualNeighbourAndMarkConnected(i,j,heights);
            return;
        }
        //---------------------------------------------------------------
        //left
        if(  j-1 >= 0 )
        {
             DFSOnDirection(i,j,i,j-1,heights);
        }
        //---------------------------------------------------------------
        //up
        if(  i-1 >= 0 )            
        {
            DFSOnDirection(i,j,i-1,j,heights);
        }
        
        //---------------------------------------------------------------
        //right
        if(  j+1 < c )
        {
            DFSOnDirection(i,j,i,j+1,heights);
        }
        //---------------------------------------------------------------
        //down
        if( i+1 < r )
        {
            DFSOnDirection(i,j,i+1,j,heights);
        }
        
        //(0,n-1) and (n-1,0) and for true elements
        if(connected[i][j] == pair<bool,bool>(true,true))
        {
            CheckEqualNeighbourAndMarkConnected(i,j,heights);
            return;
        }
    }
    //=============================================================================================
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) 
    {        
        r = heights.size();
        c = heights[0].size();        
            
        visited.assign(r, vector<bool> ());
        for(auto& v : visited) 
            v.assign(c , false);
     
        connected.assign(r, vector<pair<bool,bool>> ());
        for(auto& v : connected) 
            v.assign(c , pair<bool,bool> (false,false));
        
        //-----------------------------------------
        for(int i=0;i<r;++i)
        {
            for(int j=0;j<c;++j)
            {
               if(i==0 || j ==0)                
                 connected[i][j].first = true;
                
                if(i==r-1 || j ==c-1)                
                 connected[i][j].second = true;
            }
        }
        //-------------------------------------------
        for(int i=0;i<r;++i)
        {
            for(int j=0;j<c;++j)
            {
                if(visited[i][j] == false)
                    DFS(i,j,heights);
            }
        }
        vector<vector<int>> result;
        for_each(res.begin(),res.end(), 
            [&result](pair<int,int> val) 
                { 
                    vector<int> v; 
                    v.push_back(val.first);
                    v.push_back(val.second);
                    result.push_back(v);
                });
    return result;
    }
};
