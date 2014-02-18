#include "QuadTree.h"

QuadTreeNode::QuadTreeNode(const int depth)
{
	nodeChildren.clear();
	nodeChildren.reserve(4);
	
	
	nodeBoundingBox = NULL;
	parentNode = NULL;
	isNodeFull = false;
	nodeDepth = depth;
}

void QuadTreeNode::Split()
{
    if(!IsLeaf())
		this->DestroyAllChildren();

	CreateNewChildren();
}

void QuadTreeNode::DestroyAllChildren()
{
    for(int i = 0; i < nodeChildren.size(); i++)
	{
    	DestroyChild(nodeChildren[i]);
	}
}

void QuadTreeNode::DestroyChild(QuadTreeNode * child)
{
	for(int k = 0; k < child->nodeObjects.size(); ++k)
	{
		this->nodeObjects.push_back(child->nodeObjects[k]);
	}
	
	child->nodeObjects.clear();
}

void QuadTreeNode::CreateNewChildren()
{
    for(int i = 0; i < nodeChildren.size(); ++i)
	{
		
		nodeChildren[i] = new QuadTreeNode(++nodeDepth);
		nodeChildren[i]->SetParent(this);
		nodeChildren[i]->SetBoundingBox(GetChildBoundingBox(i));
		
		MoveNodeObjectsToChildren(nodeChildren[i]);
	}
}

void QuadTreeNode::SetParent(QuadTreeNode * parent)
{
	parentNode = this;
}

SDL_Rect * QuadTreeNode::GetChildBoundingBox(int index)
{
	int childWidth = (nodeBoundingBox->w / 2)+1;
	int childHeight = (nodeBoundingBox->h / 2)+1;
	
	int childXQuadrant = index % 2;
	int childYQuadrant = index / 2;
	
	int childXPosition = nodeBoundingBox->x + (childXQuadrant * childWidth);
	int childYPosition = nodeBoundingBox->y + (childYQuadrant * childHeight);
	
	return new SDL_Rect
				{
					childXPosition,
					childYPosition,
					childWidth,
					childHeight
				};
}

void QuadTreeNode::MoveNodeObjectsToChildren(QuadTreeNode * child)
{
	for(int j = 0; j < nodeObjects.size(); ++j)
	{
		MoveToChildIfCollisionOccurs(child,j);
	}
}

void QuadTreeNode::MoveToChildIfCollisionOccurs(QuadTreeNode * child, int entityIndex)
{
	if(child->NodeCollision(nodeObjects[entityIndex]))
	{
		child->Insert(nodeObjects[entityIndex],0,true);
		this->nodeObjects.erase(this->nodeObjects.begin() + entityIndex);
	}
}

bool QuadTreeNode::Insert(GameEntity * entity,  int maxObjectsInTree, bool forceIntoNode)
{
	if(IsFull() && !forceIntoNode)
		return false;
	
	nodeObjects.push_back(entity);
	
	isNodeFull = nodeObjects.size() >= maxObjectsInTree;
	
	return true;
}

bool QuadTreeNode::Remove(GameEntity * entity)
{
	for(int m = 0; m < nodeObjects.size(); ++m)
	{
		if(nodeObjects[m] == entity)
		{
			nodeObjects.erase(nodeObjects.begin() + m);
			return true;
		}
	}
	
	return false;
}

bool QuadTreeNode::NodeCollision(const GameEntity * entity)
{
	return entity->CheckCollision(nodeBoundingBox);
}

bool QuadTreeNode::ChildCollision(const GameEntity * entity)
{
	if(!this->HasChildren())
		return false;

	for(int n = 0; n < QuadTreeNodeCapacity; ++n)
	{
		if(SdlRectCollision::Collides(entity->BoundingBox,nodeChildren[n]->nodeBoundingBox))
			return true;
	}

	return false;
}

bool QuadTreeNode::HasChildren()
{
	return !nodeChildren.empty();
}

bool QuadTreeNode::IsLeaf()
{
	return nodeChildren.empty();
}

bool QuadTreeNode::IsFull()
{
	return isNodeFull;
}

bool QuadTreeNode::CanSplit(const int maxSize)
{
	return depth < maxSize;
}

void DestroyQuadTree()
{
	if(HasChildren())
		DestroyChildren();
	nodeObjects.clear();
}

void QuadTreeNode::SetBoudingBox(SDL_Rect * boundingBox)
{
	nodeBoundingBox = boundingBox;
}

std::vector<QuadTreeNode*> * QuadTreeNode::GetNodeChildren()
{
	return &nodeChildren;
}

std::vector<GameEntity*> * QuadTreeNode::GetNodeObjects()
{
	return &nodeObjects;
}

QuadTreeNode * QuadTreeNode::GetParentNode()
{
	return this->parentNode;
}