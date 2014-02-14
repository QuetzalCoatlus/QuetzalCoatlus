#include <QuadTree.h>

QuadTreeNode::QuadTreeNode(const int depth = 0)
{
	nodeChildren.clear();
	nodeChildren.reserve(4);
	
	NodeBoundingBox.x = 0;
	NodeBoundingBox.y = 0;
	NodeBoundingBox.w = 0;
	NodeBoundingBox.h = 0;
	
	nodeDepth = depth;
	parentNode = NULL;
	isNodeFull = false;
	isNodeLeaf = true;
}

void QuadTreeNode::Split()
{
    if(!isNodeLeaf)
		this->DestroyOldChildren();

	CreateNewChildren();
}

private void DestroyOldChildren()
{
    for(int i = 0; i < nodeChildren.size(); i++)
    	nodeChildren[i].DestroyQuadTree();
}

private void CreateNewChildren()
{
    for(int i = 0; i < nodeChildren.size(); i++)
	{
		
		nodeChildren[i] = new QuadTreeNode(++nodeDepth);
		nodeChildren[i].SetParent(this);
		nodeChildren[i].SetBoundingBox(GetChildBoundingBox(index));
		
		moveNodeObjectsToChildren(nodeChildren[i]);
	}
}

private void GetChildBoundingBox(int index)
{
	int childWidth = ++(nodeBoundingBox->w / 2);
	int childHeight = ++(nodeBoundingBox->h / 2);
	
	int childXQuadrant = index % 2;
	int childYQuadrant = index / 2;
	
	int childXPosition = nodeBoundingBox->x + (childXQuadrant * childWidth);
	int childYPosition = nodeBoundingBox->y + (childYQuadrant * childHeight);
	
	return new SDL_Rect
						{
							x = childXPosition,
							y = childYPosition,
							w = childWidth,
							h = childHeight
						};
}

private void MoveNodeObjectsToChildren(QuadTreeNode * child)
{
	for(int j = 0; j < nodeObjects.size(); j++)
	{
		MoveToChildIfCollisionOccurs(child,j);
	}
}

private void MoveToChildIfCollisionOccurs(QuadTreeNode * child, int entityIndex)
{
	if(child->NodeCollision(entity))
	{
		child->Insert(nodeObjects[entityIndex]);
		this->nodeObjects.erase(this->nodeObjects.begin() + entityIndex);
	}
}