#include "../Game/ContainerItemObject.h"
#include "../Game/Game.h"
#include "../State/Container.h"

namespace Falltergeist
{
    namespace Game
    {
        ContainerItemObject::ContainerItemObject() : ItemObject()
        {
            _subtype = Subtype::CONTAINER;
        }

        std::vector<ItemObject*>* ContainerItemObject::inventory()
        {
            return &_inventory;
        }

        void ContainerItemObject::use_p_proc(CritterObject* usedBy)
        {
            auto state = new State::Container();
            state->setObject(this);
            Game::getInstance()->pushState(state);
        }
    }
}
