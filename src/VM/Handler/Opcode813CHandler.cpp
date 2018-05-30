/*
 * Copyright 2012-2014 Falltergeist Developers.
 *
 * This file is part of Falltergeist.
 *
 * Falltergeist is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Falltergeist is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Falltergeist.  If not, see <http://www.gnu.org/licenses/>.
 */

// Related headers
#include "../../VM/Handler/Opcode813CHandler.h"

// C++ standard includes

// Falltergeist includes
#include "../../Game/CritterObject.h"
#include "../../Logger.h"
#include "../../VM/Script.h"

// Third party includes

namespace Falltergeist {
    namespace VM {
        namespace Handler {
            Opcode813C::Opcode813C(std::shared_ptr<VM::Script> script) : OpcodeHandler(script) {
            }

            void Opcode813C::_run() {
                int amount = _script->dataStack()->popInteger();
                int skill = _script->dataStack()->popInteger();
                auto critter = static_cast<Game::CritterObject *>(_script->dataStack()->popObject());

                critter->setSkillGainedValue((SKILL) skill, critter->skillGainedValue((SKILL) skill) + amount);

                Logger::debug("SCRIPT")
                        << "[813C] void critter_mod_skill(GameCritterObject* who, int skill, int amount)" << std::endl
                        << "    skill = " << skill << std::endl
                        << "    amount = " << amount << std::endl;
            }
        }
    }
}
