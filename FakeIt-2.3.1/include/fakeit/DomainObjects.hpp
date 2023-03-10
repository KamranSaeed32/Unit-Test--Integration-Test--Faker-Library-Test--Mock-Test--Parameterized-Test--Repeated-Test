/*
 * Copyright (c) 2014 Eran Pe'er.
 *
 * This program is made available under the terms of the MIT License.
 *
 * Created on Mar 10, 2014
 */
#pragma once

#include <string>

namespace fakeit {

    struct FakeitContext;

    template<typename C>
    struct MockObject {
        virtual ~MockObject() FAKEIT_THROWS { };

        virtual C &get() = 0;

        virtual FakeitContext &getFakeIt() = 0;
    };

    struct MethodInfo {

        static unsigned int nextMethodOrdinal() {
            static std::atomic_uint ordinal{0};
            return ++ordinal;
        }

        MethodInfo(unsigned int anId, std::string aName) :
                _id(anId), _name(aName) { }

        unsigned int id() const {
            return _id;
        }

        std::string name() const {
            return _name;
        }

        void setName(const std::string &value) {
            _name = value;
        }

    private:
        unsigned int _id;
        std::string _name;
    };

    struct UnknownMethod {

        static MethodInfo &instance() {
            static MethodInfo instance(MethodInfo::nextMethodOrdinal(), "unknown");
            return instance;
        }

    };

}
