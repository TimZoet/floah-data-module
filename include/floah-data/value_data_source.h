#pragma once

////////////////////////////////////////////////////////////////
// Module includes.
////////////////////////////////////////////////////////////////

#include "floah-layout/utils/floah_error.h"

////////////////////////////////////////////////////////////////
// Current target includes.
////////////////////////////////////////////////////////////////

#include "floah-data/i_value_data_source.h"

namespace floah
{
    template<typename T>
    class ValueDataSource : public IValueDataSource
    {
    public:
        ////////////////////////////////////////////////////////////////
        // Constructors.
        ////////////////////////////////////////////////////////////////

        ValueDataSource() = delete;

        explicit ValueDataSource(T& v) : value(&v) {}

        ValueDataSource(const ValueDataSource&) = delete;

        ValueDataSource(ValueDataSource&&) noexcept = delete;

        ~ValueDataSource() noexcept override = default;

        ValueDataSource& operator=(const ValueDataSource&) = delete;

        ValueDataSource& operator=(ValueDataSource&&) noexcept = delete;

        ////////////////////////////////////////////////////////////////
        // Getters.
        ////////////////////////////////////////////////////////////////

        [[nodiscard]] void* getVoid() override { return value; }

        [[nodiscard]] std::string getString() override { return std::to_string(*value); }

        [[nodiscard]] T& get() noexcept { return *value; }

        [[nodiscard]] const T& get() const noexcept { return *value; }

        ////////////////////////////////////////////////////////////////
        // Setters.
        ////////////////////////////////////////////////////////////////

        void setVoid(void* v) override { set(*static_cast<T*>(v)); }

        void setString(const std::string& v) override
        {
            // TODO: Implement.
            throw FloahError("Not implemented.");
        }

        void set(const T& v) { *value = v; }

    private:
        ////////////////////////////////////////////////////////////////
        // Member variables.
        ////////////////////////////////////////////////////////////////

        T* value = nullptr;
    };
}  // namespace floah
