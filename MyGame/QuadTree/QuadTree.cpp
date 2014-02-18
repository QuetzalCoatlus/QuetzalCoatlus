#include "QuadTree.h"

QuadTree::QuadTree(const int treeWidth, const int treeHeight)
{
	treeRoot = new QuadTreeNode();
	treeRoot->SetBoundingBox(new SDL_Rect{0,0,treeWidth,treeHeight});
}

void QuadTree::Update()
{
	for(int i = 0; i < allEntitiesInQuadTree.size(); ++i)
	{
		if(allEntitiesInQuadTree[i]->NeedsUpdate())
			UpdateEntity(allEntitiesInQuadTree[i]);
	}
}

void QuadTree::UpdateEntity(GameEntity * entity)
{
	QuadTreeNode * nodeToInsertInto;

	if (entity->GetParentNode()->GetParentNode() == NULL)
		nodeToInsertInto = entity->GetParentNode();
	else
		nodeToInsertInto = entity->GetParentNode()->GetParentNode();

	Remove(entity, entity->GetParentNode());
	Insert(entity, nodeToInsertInto);
	entity->SetStatusToUpdated();
}

bool QuadTree::Insert(GameEntity * entity, QuadTreeNode*)
{
	if(entity == NULL || treeNode == NULL)
		return false;

	bool wasSuccessful = false;

	if(startNode->IsLeaf())
		wasSuccessful = InsertIntoFullQuad(entity, startNode);
	else if (InsertIntoBranch(entity, startNode))
		wasSuccessful = true;
	else
		wasSuccessful = InsertOnUpdate(entity, startNode);

	if(wasSuccessful)
		allEntitiesInQuadTree.push_back(entity);

	return wasSuccessful;
}

bool QuadTree::InsertIntoFullQuad(GameEntity * entity, QuadTreeNode * startNode)
{
	if(startNode->Insert(entity))
		return true;
	else if(startNode->CanSplit(QuadTreeMaxDepth))
	{
		startNode->Split();
		return Insert(entity, startNode, QuadTreeMaxObjects);
	}
	else
	{
		bool forceIntoTree = true;
		startNode->Insert(entity, forceIntoTree, QuadTreeMaxObjects);
		entity->GetParentNode() = startNode;
	}
}

bool QuadTree::InsertIntoBranch(GameEntity * entity, QuadTreeNode * startNode)
{
	std::vector<QuadTreeNode*> * startNodeChildren =
			startNode->GetNodeChildren();

	for(int j = 0; j < QuadTreeNode::QuadTreeNodeCapacity; ++j)
	{
		if(startNodeChildren[j]->NodeCollision(entity))
			return Insert(entity, startNodeChildren[j], QuadTreeMaxObjects);
	}
}

bool QuadTree::InsertOnUpdate(GameEntity * entity, QuadTreeNode * startNode)
{
	if(startNode->GetParentNode() == NULL)
		return false;
	else
		Insert(entity, startNode->GetParentNode(), QuadTreeMaxObjects);
}

GameEntity * QuadTree::Collides(GameEntity * entity)
{
	return CheckLeaf(entity, treeRoot);
}

GameEntity * QuadTree::CheckLeaf(const GameEntity * entity, QuadTreeNode * startNode)
{
	if(startNode->IsLeaf())
		return CheckCollisionOnLeaf(entity, startNode);
	else
		return CheckCollisionOnChildren(entity, startNode);
}

GameEntity * QuadTree::CheckCollisionOnLeaf(GameEntity * entity, QuadTreeNode * startNode)
{
	std::vector<GameEntity*> startNodeObjects = 
		startNode->GetNodeObjects();
	for(int k = 0; k < startNodeObjects.size(); ++k)
	{
		if(startNodeObjects[k] != entity && startNodeObjects[k]->CheckCollision(entity))
			return startNodeObjects[k];
	}
}

GameEntity * QuadTree::CheckCollisionOnChildren(GameEntity * entity, QuadTreeNode * startNode)
{
	std::vector<QuadTreeNode*> startNodeChildren = 
			startNode->GetNodeChildren();

	for(int l = 0; l < QuadTreeNode::QuadTreeNodeCapacity; ++l)
	{
		GameEntity * collidingEntity = CheckLeaf(entity, startNodeChildren[i]);

		if(collidingEntity != NULL) 
			return collidingEntity;
	}

	return NULL;
}

bool QuadTree::Remove(GameEntity * entity, QuadTreeNode * startNode)
{
	if(startNode->IsLeaf())
		return startNode->Remove(entity);
	else
		RemoveFromChildren(entity, startNode);
}

bool RemoveFromChildren(GameEntity * entity, QuadTreeNode * startNode)
{
	std::vector<QuadTreeNode*> startNodeChildren = 
			startNode->GetNodeChildren();

	for(int m = 0; m < QuadTreeNode::QuadTreeNodeCapacity; ++m)
	{
		if(Remove(entity, startNodeChildren[m]))
			return true;
	}

	return false;
}