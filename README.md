Wiki_Search_Engine
==================

Built a search engine over 40GB of Wikipedia data, which includes eﬃcient indexing of documents and retrieval of search queries <br/>

201101144_M1 : Search engine to test over 300MB of wikipedia data.<br/>
Characteristics:<br/>
Indexing time : 1.6 minutes<br/>
Query time : around 1 sec overhead, then each query in O(1) time<br/>

201101144_M2 : Search engine to test over 40GB of wikipedia data.<br/>
Characteristics:<br/>
Indexing time :<br/>
240 minutes for splitting the 40GB file into chunks of 100MB + Creating partial indexes over each small file + creating the cumulative index using k-merge<br/>
20 minutes for creating 2nd order & 3rd order index over the main index file.<br/>

Query time:
Around 1sec per query
Query can be single word (Sachin)  or multi-word(Sachin Tendulkar India) or fielded query(t:sachin b:india), where t=title,b=body,c=category,o=outlinks.

