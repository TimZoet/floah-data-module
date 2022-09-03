#include "floah-data/data_source.h"

////////////////////////////////////////////////////////////////
// Standard includes.
////////////////////////////////////////////////////////////////

#include <ranges>

namespace floah
{
    ////////////////////////////////////////////////////////////////
    // Constructors.
    ////////////////////////////////////////////////////////////////

    DataSource::DataSource() = default;

    DataSource::~DataSource() noexcept = default;

    ////////////////////////////////////////////////////////////////
    // Listeners.
    ////////////////////////////////////////////////////////////////

    void DataSource::addDataListener(DataListener& listener)
    {
        if (std::ranges::find(listeners, &listener) != listeners.end()) return;

        listeners.emplace_back(&listener);
    }

    void DataSource::removeDataListener(DataListener& listener)
    {
        if (const auto it = std::ranges::find(listeners, &listener); it != listeners.end()) listeners.erase(it);
    }

    void DataSource::emitDataSourceUpdate()
    {
        for (auto* listener : listeners) listener->onDataSourceUpdate(*this);
    }

}  // namespace floah
