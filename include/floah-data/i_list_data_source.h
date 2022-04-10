#pragma once

////////////////////////////////////////////////////////////////
// Standard includes.
////////////////////////////////////////////////////////////////

#include <string>

////////////////////////////////////////////////////////////////
// Current target includes.
////////////////////////////////////////////////////////////////

#include "floah-data/data_source.h"

namespace floah
{
    class IListDataSource : public DataSource
    {
    public:
        ////////////////////////////////////////////////////////////////
        // Constructors.
        ////////////////////////////////////////////////////////////////

        IListDataSource() = default;

        IListDataSource(const IListDataSource&) = delete;

        IListDataSource(IListDataSource&&) noexcept = delete;

        ~IListDataSource() noexcept override = default;

        IListDataSource& operator=(const IListDataSource&) = delete;

        IListDataSource& operator=(IListDataSource&&) noexcept = delete;

        ////////////////////////////////////////////////////////////////
        // Getters.
        ////////////////////////////////////////////////////////////////

        [[nodiscard]] virtual size_t getSize() = 0;

        [[nodiscard]] virtual void* getVoid(size_t i) = 0;

        [[nodiscard]] virtual std::string getString(size_t i) = 0;

        ////////////////////////////////////////////////////////////////
        // Setters.
        ////////////////////////////////////////////////////////////////

        virtual void appendVoid(void* v) = 0;

        virtual void appendString(const std::string& v) = 0;

        virtual void prependVoid(void* v) = 0;

        virtual void prependString(const std::string& v) = 0;

        virtual void insertVoid(void* v, size_t i) = 0;

        virtual void insertString(const std::string& v, size_t i) = 0;

        virtual void setVoid(void* v, size_t i) = 0;

        virtual void setString(const std::string& v, size_t i) = 0;

        virtual void remove(size_t i) = 0;
    };
}  // namespace floah
