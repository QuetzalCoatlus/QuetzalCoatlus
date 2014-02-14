#include <SDL2/SDL.h>
#include <GameEntity/GameEntity.h>

class QuadTree
{
	public:
		QuadTree(const int, const int);

	public:
		bool Insert(GameEntity*);
		bool Remove(GameEntity*);
		GameEntity * Collides(GameEntity*);
		void Update();
	
	private:
		GameEntity * CheckLeaf(const GameEntity*, QuadTreeNode * startNode);

		QuadTreeNode treeRoot;
		std::vector
};
