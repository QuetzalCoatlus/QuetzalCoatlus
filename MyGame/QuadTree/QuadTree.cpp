#include <QuadTree.h>

QuadTree::QuadTree(const int depth = 0)
{
	northWestChild=NULL;
	northEastChild=NULL;
	southWestChild=NULL;
	southEastChild=NULL;	
	
	QuadTreeBoundingBox.x = 0;
	QuadTreeBoundingBox.y = 0;
	QuadTreeBoundingBox.w = 0;
	QuadTreeBoundingBox.h = 0;
}

void Split()
{
	northWestChild = new QuadTree(++depth);
	northEastChild = new QuadTree(++depth);
	southWestChild = new QuadTree(++depth);
	southEastChild = new QuadTree(++depth);
}