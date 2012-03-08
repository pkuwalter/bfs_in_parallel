/*********************************************************************
filename: alloc.cc 
author: onesuper
email: onesupperclark@gmail.com

some functions used to allocate and free graphs
*********************************************************************/

#include <stdlib.h>
#include <stdio.h>

/*
 * get a name of a graph file and read the file
 * line-by-line to generate the graph
 */ 
void graph_read_and_alloc(char* filename) 
{
	 fp = fopen(filename, "r");
	 if (!fp) {
		  printf("Cannot read the graph file.\n");
		  return;
	 }
	 unsigned int i;
	 
	 
	 /* read the number of nodes */
	 fscanf(fp, "%d", &num_of_nodes);
	 printf("************** graph **************\n");
	 printf("there are %d nodes in the graph.\n", num_of_nodes);

	 /* allocate memory of nodes according to the num_of_nodes */
	 node_list = (Node*) malloc(sizeof(Node) * num_of_nodes);
	 
	 /* read the nodes' infomation from disk to memory */
	 unsigned int start;
	 unsigned int edge_num;
	 for (i=0; i<num_of_nodes; i++) {
		  fscanf(fp, "%u %u", &start, &edge_num);
		  node_list[i].start = start;
		  node_list[i].edge_num = edge_num = edge_num;
	 }

	 /* read the source node */
	 fscanf(fp, "%u", &source_node_no);
	 printf("the source node is %u.\n", source_node_no);
	 
	 /* read the number of edges */
	 fscanf(fp, "%u", &num_of_edges);
	 printf("there are %u edges in the graph.\n", num_of_edges);

	 /* allocate the memroy of edges according to num_of_edges */
	 edge_list = (Edge*) malloc(sizeof(Edge) * num_of_edges);
	 
	 /* read the edges' information from disk to memory */
	 unsigned int dest;
	 unsigned int cost;
	 for (i=0; i<num_of_edges; i++) {
		  fscanf(fp, "%u %u", &dest, &cost);
		  edge_list[i].dest = dest;
		  edge_list[i].cost = cost;
	 }
	 

	 fclose(fp);
	 return;
}

void graph_free(void) 
{
	 free(node_list);
	 free(edge_list);
	 return;
	 
}

/*
 * have a look at the memory to verify
 */
void graph_watch(void)
{
	 unsigned int i;
	 printf("************ node **************\n");	 
	 for (i=0; i<num_of_nodes; i++) {
		  printf("%d %d\n", node_list[i].start, node_list[i].edge_num);
	 }
	 printf("************ edge **************\n");
	 for (i=0; i<num_of_edges; i++) {
		  printf("%d %d\n", edge_list[i].dest, edge_list[i].cost);
	 }
	 return;
}
	 
	 