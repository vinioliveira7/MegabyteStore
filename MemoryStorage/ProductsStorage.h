//
// Created by luanr on 05/11/2022.
//

#ifndef MEGABYTESTORE_PRODUCTSSTORAGE_H
#define MEGABYTESTORE_PRODUCTSSTORAGE_H

#include "vector"
#include "../Models/Product.h"

namespace MemoryStorage {

    class ProductsStorage {
    private:
        std::vector<Models::Product*> products;

    public:
        ProductsStorage() = default;
        ProductsStorage(std::vector<Models::Product*> loadedProducts);

        void AddProduct(Models::Product* product);
        void RemoveProduct(int index);
        void Clear();

        std::vector<Models::Product*> getProducts() const;
    };

} // MemoryStorage

#endif //MEGABYTESTORE_PRODUCTSSTORAGE_H